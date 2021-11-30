# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.205.2/containers/javascript-node/.devcontainer/base.Dockerfile

# [Choice] Node.js version (use -bullseye variants on local arm64/Apple Silicon): 16, 14, 12, 16-bullseye, 14-bullseye, 12-bullseye, 16-buster, 14-buster, 12-buster
ARG VARIANT="16-bullseye"
FROM mcr.microsoft.com/vscode/devcontainers/javascript-node:0-${VARIANT}

# Install emscripten dependencies
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
     && apt-get -y install --no-install-recommends cmake git python3 python3-pip

ENV EMSDK /emsdk

RUN git clone https://github.com/emscripten-core/emsdk.git ${EMSDK}
RUN cd ${EMSDK} \
    && ./emsdk install 1.40.1 \
    && ./emsdk activate 1.40.1 \
    && . ./emsdk_env.sh

USER node

# Install rust via rustup
ARG RUST_VERSION=1.56.1
RUN curl https://sh.rustup.rs -sSf | \
    sh -s -- -y --default-toolchain $RUST_VERSION && \
    . ~/.cargo/env && \
    echo "source ~/.cargo/env" >> ~/.bashrc && \
    echo "source /emsdk/emsdk_env.sh" >> ~/.bashrc && \
    rustup target add asmjs-unknown-emscripten && \
    rustup target add wasm32-unknown-emscripten

# [Optional] Uncomment this section to install additional OS packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>

# [Optional] Uncomment if you want to install an additional version of node using nvm
# ARG EXTRA_NODE_VERSION=10
# RUN su node -c "source /usr/local/share/nvm/nvm.sh && nvm install ${EXTRA_NODE_VERSION}"

# [Optional] Uncomment if you want to install more global node modules
# RUN su node -c "npm install -g <your-package-list-here>"
