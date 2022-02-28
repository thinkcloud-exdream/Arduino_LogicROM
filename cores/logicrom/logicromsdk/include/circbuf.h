/*
 * circular_buf.h
 *
 */

#ifndef INC_CIRCULAR_BUF_H_
#define INC_CIRCULAR_BUF_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Create a circular buffer
 * @param size		[in] Maximum size of buffer
 * @return			On success handle to buffer object is returned, 0 on error.
 */
int circbuf_create(int size);

/**
 * Delete circular buffer
 * @param handle	[in] Handle to circular buffer
 * @return			0 on success
 */
int circbuf_delete(int handle);

/**
 * Store one byte to circular buffer
 * @param handle	[in] Handle to circular buffer
 * @param data		[in] Data byte
 * @return			0 on success, -1 on error
 */
int circbuf_push_byte(int handle, unsigned char data);

/**
 * Store buffered data to circular buffer
 * @param handle	[in] Handle to circular buffer
 * @param data		[in] input data buffer
 * @param len		[in] Length of data in buffer
 * @return			returns actual number of bytes pushed
 */
int circbuf_push(int handle, unsigned char *data, unsigned int len);

/**
 * Read one byte from circular buffer
 * @param handle	[in] Handle to circular buffer
 * @param data		[out] Pointer to read buffer
 * @return			0 on success, -1 on error
 */
int circbuf_pop_byte(int handle, unsigned char *data);

/**
 * Read data from circular buffer
 * @param handle	[in] Handle to circular buffer
 * @param data		[out] pointer to read buffer
 * @param len		[in] Length of data to read
 * @return			On success, returns actual length read, negative value on error
 */
int circbuf_pop(int handle, unsigned char *data, unsigned int len);

/**
 * Peek a byte from head of circular buffer. Subsequent calls
 * to this function will lead to same byte unless @ref circbuf_pop or
 * @ref circbuf_pop_byte is called.
 * @param handle	[in] Handle to circular buffer
 * @param data		[out] Pointer to read buffer
 * @return			On success, returns actual length read, negative value on error
 */
int circbuf_peek_byte(int handle, unsigned char *data);

/**
 * Peek data from start of circular buffer. Data will not be removed
 * from buffer unless @ref circbuf_pop or @ref circbuf_pop_byte is called.
 * @param handle	[in] Handle to circular buffer
 * @param data		[out] pointer to read buffer
 * @param len		[in] Length of data to read
 * @return			On success, returns actual length read, negative value on error
 */
int circbuf_peek(int handle, unsigned char *data, int len);

/**
 * Check if buffer is empty
 * @param handle	[in] Handle to circular buffer
 * @return			1 if empty, 0 otherwise
 */
int circbuf_isempty(int handle);

/**
 * Get available bytes in buffer
 * @param handle	[in] Handle to circular buffer
 * @return			number of bytes available or negative value on error
 */
int circbuf_getcount(int handle);

/**
 * Clear and reset circular buffer
 * @param handle	[in] Handle to circular buffer
 * @return			Always returns 0
 */
int circbuf_reset(int handle);

#ifdef __cplusplus
}
#endif

#endif /* INC_CIRCULAR_BUF_H_ */
