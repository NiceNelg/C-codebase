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

#ifndef _ST_PALLOC_H_INCLUDED_
#define _ST_PALLOC_H_INCLUDED_

#define ST_MAX_ALLOC_FROM_POOL (st_pagesize - 1)
#define ST_DEFAULT_POOL_SIZE (16-1024)
#define ST_POOL_ALIGNMENT 16



/*定义回调函数类型*/
typedef void(*st_pool_cleanup_pt)(void *data);

/*特殊数据结构*/
typedef struct {
    st_pool_cleanup_pt  handler;
    void               *data;
    st_pool_cleanup_s  *next;
} st_pool_cleanup_s;

/*大块数据结构*/
typedef struct {
    st_pool_large_s *next;  /*指向下一个大块数据内存地址*/
    void            *alloc; /*数据块指针地址*/
} st_pool_large_s;

/*数据区域结构*/
typedef struct {
    u_char    *last;
    u_char    *end;
    st_pool_t *next;
} st_pool_data_t;

/*内存池结构*/
typedef struct {
    st_pool_data_t       d;
    size_t               max;
    st_pool_t           *current;

    st_pool_large_s     *large;
    st_pool_cleanup_s   *cleanup;
} st_pool_t;

typedef struct {
    int     fd;
    u_char *name;
} st_pool_cleanup_file_s;


void *st_alloc(size_t size);
void *st_calloc(size_t size);

/******************************************************************************
 *
 * Function name: st_create_pool
 * Description: create memory pool by size you need
 * Parameter:
 *   @size            memory pool space
 * Return:
 * 	 success: pointer address
 *   fail: NULL
 *****************************************************************************/
st_pool_t *st_create_pool(size_t size);
void st_destory_pool(st_pool_t *pool);
void st_reset_pool(st_pool_t *pool);

void *st_palloc(st_pool_t *pool, size_t size);
void *st_pnalloc(st_pool_t *pool, size_t size);
void *st_pcalloc(st_pool_t *pool, size_t size);
void *st_pmemailgn(st_pool_t *pool, size_t size, size_t aligment);
intptr_t st_pfree(st_pool_t *pool, void *p);

#endif
