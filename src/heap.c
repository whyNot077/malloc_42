#include "malloc.h"

static size_t get_page_size(size_t size);

Pointer extend_heap(size_t words)
{
    words = get_page_size(words);
    add_log_detail("extend_heap");
    Pointer prologue_bp = new_heap(words);
    if (!prologue_bp)
    {
        return prologue_bp;
    }
    add_log(NEW_HEAP, prologue_bp, GET_SIZE(HEAD(prologue_bp)));
    insert_to_vector(prologue_bp);
    return coalesce(NEXT_BLK(prologue_bp), get_pool_type(words));
}

Base new_heap(size_t words)
{
    size_t size = get_aligned_size(words + PROLOGUE_SIZE + EPILOGUE_SIZE);
    Pointer res = Mmap(size);
    if (!res)
    {
        return res;
    }
    Pointer bp = (Pointer)res + WSIZE;
    // prologue block
    PUT(HEAD(bp), PACK(PROLOGUE_SIZE, true));
    PUT(FOOT(bp), PACK(PROLOGUE_SIZE, true));

    // allocated block
    Pointer next_bp = NEXT_BLK(bp);
    PUT(HEAD(next_bp), PACK(size - PROLOGUE_SIZE - EPILOGUE_SIZE, false));
    PUT(FOOT(next_bp), PACK(size - PROLOGUE_SIZE - EPILOGUE_SIZE, false));
    PUT_PTR(PREV_PTR(next_bp), 0);
    PUT_PTR(NEXT_PTR(next_bp), 0);

    // epilogue block
    PUT(HEAD(NEXT_BLK(next_bp)), PACK(0, true));
    return bp;
}

static size_t get_page_size(size_t size)
{
    size_t new_size = 0;
    size_t pagesize = getpagesize() * 4;
    size = get_aligned_size(size);
    while (new_size < size)
    {
        new_size += pagesize;
    }
    return new_size;
}