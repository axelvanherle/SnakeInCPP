FROM ubuntu:latest
COPY . .
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget
RUN g++ ticTacToeInCPP/*.cpp -o ticTacToe
ENTRYPOINT ["./ticTacToe"]
