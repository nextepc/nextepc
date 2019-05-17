ARG dist=centos
ARG tag=latest
ARG username=nextepc
FROM ${username}/${dist}-${tag}-nextepc-base

MAINTAINER NextEPC <help@nextepc.com>

RUN yum -y install \
        cscope \
        vim \
        sudo \
        iputils \
        net-tools

COPY setup.sh /root

ARG username=nextepc
RUN useradd -m --uid=1000 ${username} && \
    echo "${username} ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/${username} && \
    chmod 0440 /etc/sudoers.d/${username}

WORKDIR /home/${username}
