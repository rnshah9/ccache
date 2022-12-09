FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libzstd-dev clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DREDIS_STORAGE_BACKEND=OFF -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install
RUN clang++ /repo/mayhem/fuzz_format_human_readable_size.cpp -fsanitize=fuzzer,address -I /repo/src/ -std=c++17 -L /repo/build/src/ -lccache_framework -L /repo/build/src/third_party/ -lthird_party -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_format_human_readable_size
