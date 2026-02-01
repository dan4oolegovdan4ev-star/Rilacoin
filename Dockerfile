# Използваме официален Ubuntu образ като база
FROM ubuntu:22.04

# Задаваме работната директория
WORKDIR /app

# Инсталираме основните зависимости за Monero/Rilacoin
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    pkg-config \
    libboost-all-dev \
    libssl-dev \
    libzmq3-dev \
    libunbound-dev \
    libminiupnpc-dev \
    libsodium-dev \
    libhidapi-dev \
    libreadline-dev \
    wget \
    curl \
    ca-certificates \
    python3 \
    ninja-build \
    && rm -rf /var/lib/apt/lists/*

# Копираме целия репо в контейнера
COPY . /app

# Създаваме директория за билд
RUN mkdir -p build && cd build && cmake .. -DCMAKE_BUILD_TYPE=Release && make -j$(nproc)

# Експоузваме стандартния RPC порт на Rilacoin daemon
EXPOSE 18081

# Задаваме командата за стартиране на daemon-а
CMD ["./build/src/daemon/rilacoin-daemon", "--non-interactive", "--detach"]
