#include <vd2/system/vdtypes.h>
#include <vd2/Kasumi/pixmap.h>
#include <vd2/Kasumi/pixmaputils.h>

#define DECLARE_PALETTED(x, y) void VDPixmapBlt_##x##_to_##y##_reference(void *dst0, ptrdiff_t dstpitch, const void *src0, ptrdiff_t srcpitch, vdpixsize w, vdpixsize h, const void *pal0)

///////////////////////////////////////////////////////////////////////////
//
//	RGB blitters: Pal1 ->
//
///////////////////////////////////////////////////////////////////////////

DECLARE_PALETTED(Pal1, Any16) {
	const uint8 *src = (const uint8 *)src0;
	uint16 *dst = (uint16 *)dst0;
	const uint16 *pal = (const uint16 *)pal0;

	dst += (w & ~7);

	srcpitch -= (w+7) >> 3;
	dstpitch += (w+7) & ~7;

	do {
		int wt = w;

		uint8 v = src[0] >> ((-wt) & 7);
		
		switch(wt & 7) {
			do {
				v = src[0];

		case 0:	dst[7] = pal[v&1];	v >>= 1;
		case 7:	dst[6] = pal[v&1];	v >>= 1;
		case 6:	dst[5] = pal[v&1];	v >>= 1;
		case 5:	dst[4] = pal[v&1];	v >>= 1;
		case 4:	dst[3] = pal[v&1];	v >>= 1;
		case 3:	dst[2] = pal[v&1];	v >>= 1;
		case 2:	dst[1] = pal[v&1];	v >>= 1;
		case 1:	dst[0] = pal[v&1];	v >>= 1;

				dst -= 8;
				--src;
			} while((wt -= 8) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal1, Any24) {
	const uint8 *src = (const uint8 *)src0;
	uint8 *dst = (uint8 *)dst0;
	const uint8 *pal = (const uint8 *)pal0;

	dst += (w & ~7) * 3;

	srcpitch -= (w+7) >> 3;
	dstpitch += (w+7) & ~7;

	do {
		int wt = w;

		uint8 v = src[0] >> ((-wt) & 7);
		const uint8 *pe;
		
		switch(wt & 7) {
			do {
				v = src[0];

		case 0:	pe = &pal[3*(v&1)]; dst[7*3+0] = pe[0]; dst[7*3+1] = pe[1]; dst[7*3+2] = pe[2]; v >>= 1;
		case 7:	pe = &pal[3*(v&1)]; dst[6*3+0] = pe[0]; dst[6*3+1] = pe[1]; dst[6*3+2] = pe[2]; v >>= 1;
		case 6:	pe = &pal[3*(v&1)]; dst[5*3+0] = pe[0]; dst[5*3+1] = pe[1]; dst[5*3+2] = pe[2]; v >>= 1;
		case 5:	pe = &pal[3*(v&1)]; dst[4*3+0] = pe[0]; dst[4*3+1] = pe[1]; dst[4*3+2] = pe[2]; v >>= 1;
		case 4:	pe = &pal[3*(v&1)]; dst[3*3+0] = pe[0]; dst[3*3+1] = pe[1]; dst[3*3+2] = pe[2]; v >>= 1;
		case 3:	pe = &pal[3*(v&1)]; dst[2*3+0] = pe[0]; dst[2*3+1] = pe[1]; dst[2*3+2] = pe[2]; v >>= 1;
		case 2:	pe = &pal[3*(v&1)]; dst[1*3+0] = pe[0]; dst[1*3+1] = pe[1]; dst[1*3+2] = pe[2]; v >>= 1;
		case 1:	pe = &pal[3*(v&1)]; dst[0*3+0] = pe[0]; dst[0*3+1] = pe[1]; dst[0*3+2] = pe[2]; v >>= 1;

				dst -= 8;
				--src;
			} while((wt -= 8) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal1, Any32) {
	const uint8 *src = (const uint8 *)src0;
	uint32 *dst = (uint32 *)dst0;
	const uint32 *pal = (const uint32 *)pal0;

	dst += (w & ~7);

	srcpitch -= (w+7) >> 3;
	dstpitch += (w+7) & ~7;

	do {
		int wt = w;

		uint8 v = src[0] >> ((-wt) & 7);
		
		switch(wt & 7) {
			do {
				v = src[0];

		case 0:	dst[7] = pal[v&1];	v >>= 1;
		case 7:	dst[6] = pal[v&1];	v >>= 1;
		case 6:	dst[5] = pal[v&1];	v >>= 1;
		case 5:	dst[4] = pal[v&1];	v >>= 1;
		case 4:	dst[3] = pal[v&1];	v >>= 1;
		case 3:	dst[2] = pal[v&1];	v >>= 1;
		case 2:	dst[1] = pal[v&1];	v >>= 1;
		case 1:	dst[0] = pal[v&1];	v >>= 1;

				dst -= 8;
				--src;
			} while((wt -= 8) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

///////////////////////////////////////////////////////////////////////////
//
//	RGB blitters: Pal2 ->
//
///////////////////////////////////////////////////////////////////////////

DECLARE_PALETTED(Pal2, Any16) {
	const uint8 *src = (const uint8 *)src0;
	uint16 *dst = (uint16 *)dst0;
	const uint16 *pal = (const uint16 *)pal0;

	dst += (w & ~3);

	srcpitch -= (w+3) >> 2;
	dstpitch += (w+3) & ~3;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 3)*2);
		
		switch(wt & 3) {
			do {
				v = src[0];

		case 0:	dst[3] = pal[v&3];	v >>= 2;
		case 3:	dst[2] = pal[v&3];	v >>= 2;
		case 2:	dst[1] = pal[v&3];	v >>= 2;
		case 1:	dst[0] = pal[v&3];	v >>= 2;

				dst -= 4;
				--src;
			} while((wt -= 4) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal2, Any24) {
	const uint8 *src = (const uint8 *)src0;
	uint8 *dst = (uint8 *)dst0;
	const uint8 *pal = (const uint8 *)pal0;

	dst += (w & ~3) * 3;

	srcpitch -= (w+3) >> 2;
	dstpitch += (w+3) & ~3;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 3)*2);
		const uint8 *pe;
		
		switch(wt & 3) {
			do {
				v = src[0];

		case 0:	pe = &pal[3*(v&3)]; dst[3*3+0] = pe[0]; dst[3*3+1] = pe[1]; dst[3*3+2] = pe[2]; v >>= 2;
		case 3:	pe = &pal[3*(v&3)]; dst[2*3+0] = pe[0]; dst[2*3+1] = pe[1]; dst[2*3+2] = pe[2]; v >>= 2;
		case 2:	pe = &pal[3*(v&3)]; dst[1*3+0] = pe[0]; dst[1*3+1] = pe[1]; dst[1*3+2] = pe[2]; v >>= 2;
		case 1:	pe = &pal[3*(v&3)]; dst[0*3+0] = pe[0]; dst[0*3+1] = pe[1]; dst[0*3+2] = pe[2]; v >>= 2;

				dst -= 4;
				--src;
			} while((wt -= 4) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal2, Any32) {
	const uint8 *src = (const uint8 *)src0;
	uint32 *dst = (uint32 *)dst0;
	const uint32 *pal = (const uint32 *)pal0;

	dst += (w & ~3);

	srcpitch -= (w+3) >> 2;
	dstpitch += (w+3) & ~3;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 3)*2);
		
		switch(wt & 3) {
			do {
				v = src[0];

		case 0:	dst[3] = pal[v&3];	v >>= 2;
		case 3:	dst[2] = pal[v&3];	v >>= 2;
		case 2:	dst[1] = pal[v&3];	v >>= 2;
		case 1:	dst[0] = pal[v&3];	v >>= 2;

				dst -= 4;
				--src;
			} while((wt -= 4) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

///////////////////////////////////////////////////////////////////////////
//
//	RGB blitters: Pal4 ->
//
///////////////////////////////////////////////////////////////////////////

DECLARE_PALETTED(Pal4, Any16) {
	const uint8 *src = (const uint8 *)src0;
	uint16 *dst = (uint16 *)dst0;
	const uint16 *pal = (const uint16 *)pal0;

	dst += (w & ~1);

	srcpitch -= (w+1) >> 1;
	dstpitch += (w+1) & ~1;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 1)*4);
		
		switch(wt & 1) {
			do {
				v = src[0];

		case 0:	dst[1] = pal[v&15];	v >>= 4;
		case 1:	dst[0] = pal[v&15];	v >>= 4;

				dst -= 2;
				--src;
			} while((wt -= 2) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal4, Any24) {
	const uint8 *src = (const uint8 *)src0;
	uint8 *dst = (uint8 *)dst0;
	const uint8 *pal = (const uint8 *)pal0;

	dst += (w & ~1) * 3;

	srcpitch -= (w+1) >> 1;
	dstpitch += (w+1) & ~1;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 1)*4);
		const uint8 *pe;
		
		switch(wt & 1) {
			do {
				v = src[0];

		case 0:	pe = &pal[3*(v&15)]; dst[1*3+0] = pe[0]; dst[1*3+1] = pe[1]; dst[1*3+2] = pe[2]; v >>= 4;
		case 1:	pe = &pal[3*(v&15)]; dst[0*3+0] = pe[0]; dst[0*3+1] = pe[1]; dst[0*3+2] = pe[2]; v >>= 4;

				dst -= 2;
				--src;
			} while((wt -= 2) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal4, Any32) {
	const uint8 *src = (const uint8 *)src0;
	uint32 *dst = (uint32 *)dst0;
	const uint32 *pal = (const uint32 *)pal0;

	dst += (w & ~1);

	srcpitch -= (w+1) >> 1;
	dstpitch += (w+1) & ~1;

	do {
		int wt = w;

		uint8 v = src[0] >> (((-wt) & 1)*4);
		
		switch(wt & 1) {
			do {
				v = src[0];

		case 0:	dst[1] = pal[v&15];	v >>= 4;
		case 1:	dst[0] = pal[v&15];	v >>= 4;

				dst -= 2;
				--src;
			} while((wt -= 2) > 0);
		}

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

///////////////////////////////////////////////////////////////////////////
//
//	RGB blitters: Pal8 ->
//
///////////////////////////////////////////////////////////////////////////

DECLARE_PALETTED(Pal8, Any16) {
	const uint8 *src = (const uint8 *)src0;
	uint16 *dst = (uint16 *)dst0;
	const uint16 *pal = (const uint16 *)pal0;

	srcpitch -= w;
	dstpitch -= w*2;

	do {
		int wt = w;

		do {
			*dst++ = pal[*src++];
		} while(--wt);

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal8, Any24) {
	const uint8 *src = (const uint8 *)src0;
	uint8 *dst = (uint8 *)dst0;
	const uint8 *pal = (const uint8 *)pal0;

	srcpitch -= w;
	dstpitch -= w*3;

	do {
		int wt = w;
		do {
			const uint8 *pe = &pal[3**src++];

			dst[0] = pe[0];
			dst[1] = pe[1];
			dst[2] = pe[2];
			dst += 3;
		} while(--wt);

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}

DECLARE_PALETTED(Pal8, Any32) {
	const uint8 *src = (const uint8 *)src0;
	uint32 *dst = (uint32 *)dst0;
	const uint32 *pal = (const uint32 *)pal0;

	srcpitch -= w;
	dstpitch -= w*4;

	do {
		int wt = w;

		do {
			*dst++ = pal[*src++];
		} while(--wt);

		vdptrstep(src, srcpitch);
		vdptrstep(dst, dstpitch);
	} while(--h);
}
