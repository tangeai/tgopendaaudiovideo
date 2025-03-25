

#ifndef _DAG711Manager_H_
#define _DAG711Manager_H_

#ifdef __cplusplus
extern "C" {
#endif

unsigned char DAlinear2alaw(short pcm_val);
short DAalaw2linear(unsigned char	a_val);

unsigned char DAlinear2ulaw(short	pcm_val);
short DAulaw2linear(unsigned char	u_val);

unsigned char DAalaw2ulaw(unsigned char aval);
unsigned char DAulaw2alaw(unsigned char uval);

int DAg711a_Encode(unsigned char *src, unsigned int srclen,unsigned char *dest, unsigned int *dstlen);
int DAg711a_Decode(unsigned char *src, unsigned int srclen,unsigned char *dest, unsigned int *dstlen);

int DAg711u_Encode(unsigned char *src, unsigned int srclen,unsigned char *dest, unsigned int *dstlen);
int DAg711u_Decode(unsigned char *src, unsigned int srclen,unsigned char *dest, unsigned int *dstlen);

#ifdef __cplusplus
}
#endif

#endif
