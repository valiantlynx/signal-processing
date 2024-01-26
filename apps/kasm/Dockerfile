# Use an Ubuntu base image
FROM ubuntu:latest

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    curl \
    tar \
    sudo
RUN apt-get update && \
    apt-get -qy full-upgrade && \
    curl -sSL https://get.docker.com/ | sh
# change docker is installed
RUN docker --version
RUN docker ps

# install docker
RUN apt-get update -y && apt-get install -y jq
RUN apt-get install -y apt-transport-https ca-certificates curl software-properties-common
RUN curl -fsSL https://download.docker.com/linux/ubuntu/gpg | apt-key add -
RUN add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu focal stable"
RUN apt-get update -y && apt-get install -y docker-ce

# change docker is installed
RUN docker --version
RUN docker ps

# Download and install Kasm Workspaces
WORKDIR /tmp
RUN curl -O https://kasm-static-content.s3.amazonaws.com/kasm_release_1.14.0.3a7abb.tar.gz && \
    tar -xf kasm_release_1.14.0.3a7abb.tar.gz && \
    echo "y" | bash kasm_release/install.sh

# Cleanup
RUN rm -rf /tmp/*

CMD ["sh", "-c", "tail -f /dev/null"]
