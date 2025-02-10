#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

uv_udp_t server;

static viod on_socet_recv(uv_udp_t *handle,
		ssize_t nread, const uv_buf_t *buf, const struct *addr,
		unsigned flags) 
{
	if ( nread > 0 ){
		fprintf(stderr, "Buffer recvd: %.*s", (int)buf->len, buf->base);

	}
	free(buf->base);
}

static viod on_alloc(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf)
{
	buf->base = malloc(suggested_size);
	buf->len = suggested_size;
}



int main()
{
	uv_loop_t* loop = uv_default_loop();

	uv_loop_init(loop, &server);

	struct sockaddr_in addr;
	uv_ip4_addr("0.0.0.0", 6678, &addr);

	uv_udp_bind(&server, (const struct sockaddr*)&addr, 0);

	uv_udp_recv_start(&server, on_alloc, on_socket_recv);


	uv_run(loop, UV_RUN_DEFAULT);



}
