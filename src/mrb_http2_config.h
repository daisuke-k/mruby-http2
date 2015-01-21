/*
// mrb_http2_server.h - to provide http2 methods
//
// See Copyright Notice in mrb_http2.c
*/

#ifndef MRB_HTTP2_CONFIG_H
#define MRB_HTTP2_CONFIG_H

#include "mrb_http2.h"

#define MRB_HTTP2_WORKER_MAX 1024

typedef unsigned int mrb_http2_config_flag;
typedef const char mrb_http2_config_cstr;

// callback block symbol literal list
typedef struct {

  // callback block at a phase of mapping uri to filename
  const char *map_to_strage_cb;

  // callback block at a phase of creating content
  const char *content_cb;

  // callback block after send response
  const char *logging_cb;

} mruby_cb_list;

// mruby-http2 config parameter getting from HTTP2::Server#init
typedef struct {

  mrb_http2_config_flag daemon;
  mrb_http2_config_flag debug;
  mrb_http2_config_flag tls;
  mrb_http2_config_flag callback;

  // connection record option
  // default enabled and can use connection methods
  mrb_http2_config_flag connection_record;

  mrb_http2_config_cstr *key;
  mrb_http2_config_cstr *cert;
  mrb_http2_config_cstr *service;
  mrb_http2_config_cstr *document_root;

  // server response header
  mrb_http2_config_cstr *server_name;

  // server listen hostname
  mrb_http2_config_cstr *server_host;

  mruby_cb_list *cb_list;

  // the number of worker process, need SO_REUSEPORT linux kernel 3.9 or later
  unsigned int worker;

} mrb_http2_config_t;

mrb_http2_config_t *mrb_http2_s_config_init(mrb_state *mrb, mrb_value args);

#endif
