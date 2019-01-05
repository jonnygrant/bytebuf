#ifndef BYTEBUF_H
#define BYTEBUF_H

/* Intended as a replacement for tradditional C-strings
 Backwards compatible with traditional C-strings, as still internally NUL terminated.
 There is no tructate in these APIs, add a new bytebuf_cpy_trucate() if needed. */

struct bytebuf
{
    size_t size; /* Size in bytes */
    size_t len;  /* Length in bytes that are in use */
    uint8 * buf; /* Buffer, this is +1 to allow a NUL terminating byte after the size */
};

/* Returns 0 on success, or an errno value */
int bytebuf_alloc(struct bytebuf * buf, size_t size);
int bytebuf_free(struct bytebuf * buf);

/* Returns 0 on success, or EF2BIG if no space, EFAULT if any pointers are bad */
int bytebuf_cpy(struct bytebuf * dest, const struct bytebuf * src);

/* Returns 0 on success, or EF2BIG if no space, EFAULT if any pointers are bad */
int bytebuf_cat(struct bytebuf * dest, const struct bytebuf * src);

/* Returns 0 on success, or ENOMEM, or EFAULT if any pointers are bad */
int bytebuf_dup(struct bytebuf * dest, const struct bytebuf * src);

#endif

