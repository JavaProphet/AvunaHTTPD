//
// Created by p on 2/26/19.
//

#ifndef AVUNA_HTTPD_BUFFER_H
#define AVUNA_HTTPD_BUFFER_H

#include <stdint.h>
#include "pmem.h"
#include <stdlib.h>
#include "llist.h"

struct buffer { // TODO: linked list of fixed arrays instead
    struct mempool* pool;
    struct llist* buffers;
    size_t size;
};

struct buffer_entry {
    void* data_root;
    void* data;
    size_t size;
};

void buffer_init(struct buffer* buffer, struct mempool* pool);

void buffer_push(struct buffer* buffer, void* data, size_t size);

void buffer_skip(struct buffer* buffer, size_t size);

size_t buffer_pop(struct buffer* buffer, size_t size, uint8_t* data);

#endif //AVUNA_HTTPD_BUFFER_H
