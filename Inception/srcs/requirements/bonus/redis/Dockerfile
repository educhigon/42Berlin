FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y redis

EXPOSE 6379
CMD ["redis-server", "--bind", "0.0.0.0", "--protected-mode", "no"]
