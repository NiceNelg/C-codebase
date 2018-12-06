/******************************************************************************
 * Copyright(C),2010-2011,nicenelg@gmail.com
 * FileName: st_palloc.h
 * Author: Nelg
 * Version: v0.0.1
 * Date: 2018-12-06
 * Description: single thred memory pool
 * Others: 
 * Function List:
 * History:
 *****************************************************************************/

#include "st_palloc.h"

static void *st_palloc_block(st_pool_t *pool, size_t size);
static void *st_palloc_large(st_pool_t *pool, size_t size);

st_pool_t *
st_create_pool(size_t size)
{}
