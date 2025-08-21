#!/bin/bash
set -e

# === Configuration ===
UBUNTU_VERSION="noble"  # Can be: jammy, focal, noble, etc.
IMAGE_NAME="ubuntu.img"
CLOUD_INIT_ISO="cloud-init.iso"
VM_MEMORY="8192"
VM_CPUS="2"
SSH_PORT="2222"
VM_USER="ubuntu"
VM_PASSWORD="ubuntu"
VM_USER2="neelabh"
VM_PASSWORD2="passw0rd"

# shared folder name
SHARED_DIR=$HOME/share_with_vm
SHARED_TAG="shared_data"

if [ ! -d "$SHARED_DIR" ]; then
    echo "[*] Shared folder doesn't exist, creating...."
    mkdir -p "$SHARED_DIR"
fi

# === Paths ===
CLOUD_IMAGE_URL="https://cloud-images.ubuntu.com/${UBUNTU_VERSION}/current/${UBUNTU_VERSION}-server-cloudimg-amd64.img"

# === Check dependencies ===
echo "[*] Checking dependencies..."
for cmd in wget qemu-system-x86_64 cloud-localds; do
    command -v $cmd >/dev/null 2>&1 || { echo "❌ $cmd is not installed. Please install it."; exit 1; }
done

# === Download Ubuntu Cloud Image ===
if [ ! -f "$IMAGE_NAME" ]; then
    echo "[*] Downloading Ubuntu cloud image..."
    wget -O "$IMAGE_NAME" "$CLOUD_IMAGE_URL"
else
    echo "[*] Using existing image: $IMAGE_NAME"
fi

# === Generate SSH key if missing ===
if [ ! -f ~/.ssh/id_rsa.pub ]; then
    echo "[*] SSH key not found. Generating..."
    ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
fi
SSH_KEY=$(cat ~/.ssh/id_rsa.pub)
SSH_KEY_ED=$(cat ~/.ssh/id_ed25519.pub)

# === Create user-data ===
echo "[*] Creating user-data file..."
cat > user-data <<EOF
#cloud-config
hostname: ubuntu-vm
users:
  - name: ${VM_USER}
    sudo: ALL=(ALL) NOPASSWD:ALL
    groups: users, admin
    shell: /bin/bash
    lock_passwd: false
    plain_text_passwd: '${VM_PASSWORD}'
    ssh_authorized_keys:
      - ${SSH_KEY}
      - ${SSH_KEY_ED}
  - name: ${VM_USER2}
    sudo: ALL=(ALL) NOPASSWD:ALL
    groups: users, admin
    shell: /bin/bash
    lock_passwd: false
    plain_text_passwd: '${VM_PASSWORD2}'
    ssh_authorized_keys:
      - ${SSH_KEY}
      - ${SSH_KEY_ED}
chpasswd:
  list: |
    ${VM_USER}:${VM_PASSWORD}
    ${VM_USER2}:${VM_PASSWORD2}
  expire: False
ssh_pwauth: true
EOF

# === Create meta-data ===
echo "[*] Creating meta-data file..."
echo "instance-id: ubuntu-vm" > meta-data
echo "local-hostname: ubuntu-vm" >> meta-data

# === Generate cloud-init ISO ===
echo "[*] Generating cloud-init ISO..."
cloud-localds "$CLOUD_INIT_ISO" user-data meta-data

# === Launch VM ===
echo "[*] Starting VM..."
qemu-system-x86_64 \
  -m "$VM_MEMORY" \
  -smp "$VM_CPUS" \
  -hda "$IMAGE_NAME" \
  -drive file="$CLOUD_INIT_ISO",format=raw \
  -netdev user,id=net0,hostfwd=tcp::${SSH_PORT}-:22 \
  -device virtio-net-pci,netdev=net0 \
  -virtfs local,path=$SHARED_DIR,mount_tag=$SHARED_TAG,security_model=passthrough,id=hostshare \
  -nographic

