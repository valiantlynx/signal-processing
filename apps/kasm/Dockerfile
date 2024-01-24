# Use an Ubuntu base image
FROM ubuntu:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    curl \
    tar \
    sudo

# Download and install Kasm Workspaces
WORKDIR /tmp
RUN curl -O https://kasm-static-content.s3.amazonaws.com/kasm_release_1.14.0.3a7abb.tar.gz && \
    tar -xf kasm_release_1.14.0.3a7abb.tar.gz && \
    echo "y" | bash kasm_release/install.sh

# Cleanup
RUN rm -rf /tmp/*

CMD ["sh", "-c", "tail -f /dev/null"]
