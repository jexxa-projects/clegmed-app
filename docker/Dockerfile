# Stage 1: Build-Umgebung (Alpine ist ideal für statische Builds)
FROM alpine:latest AS builder

# Notwendige Tools für CMake und C++ installieren
RUN apk add --no-cache \
    g++ \
    cmake \
    make \
    musl-dev \
    linux-headers \
    git

ARG APP_VERSION=unknown

WORKDIR /app
COPY . .

# CMake-Konfiguration und Build
# -DCMAKE_EXE_LINKER_FLAGS="-static" erzwingt das statische Linken der Binärdatei
RUN mkdir build && cd build && \
    cmake -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXE_LINKER_FLAGS="-static" \
    -DAPP_VERSION_FROM_GIT=${APP_VERSION} .. && \
    make -j$(nproc)

# Stage 2: Das finale leere Image
FROM scratch

# Kopieren Sie die Binärdatei aus dem Build-Ordner
# Ersetzen Sie 'clegmed-app' durch den Namen Ihres Executables aus der CMakeLists.txt
COPY --from=builder /app/build/clegmed-app /clegmed-app

ENTRYPOINT ["/clegmed-app"]
