FROM ubuntu:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    curl \
    tar \
    sudo 

# Install Docker
RUN curl -fsSL https://get.docker.com -o get-docker.sh && \
    sh get-docker.sh


# test if docker are installed
RUN docker -v && echo docker ps -a

# Download and install Kasm Workspaces
WORKDIR /tmp
RUN curl -O https://kasm-static-content.s3.amazonaws.com/kasm_release_1.14.0.3a7abb.tar.gz && \
    tar -xf kasm_release_1.14.0.3a7abb.tar.gz && \
    echo "y" | bash kasm_release/install.sh

# Cleanup
RUN rm -rf /tmp/*

CMD ["sh", "-c", "tail -f /dev/null"]
