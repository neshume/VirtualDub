#ifndef f_VD2_KASUMI_UBERBLIT_H
#define f_VD2_KASUMI_UBERBLIT_H

#include <vd2/system/vdtypes.h>
#include <vd2/system/vdstl.h>
#include <vd2/system/vectors.h>

struct VDPixmap;

enum VDPixmapFormatToken {
	kVDPixType_1			= 0x00000001,
	kVDPixType_2			= 0x00000002,
	kVDPixType_4			= 0x00000003,
	kVDPixType_8			= 0x00000004,
	kVDPixType_555_LE		= 0x00000005,
	kVDPixType_565_LE		= 0x00000006,
	kVDPixType_1555_LE		= 0x00000007,
	kVDPixType_888			= 0x00000008,
	kVDPixType_8888			= 0x00000009,
	kVDPixType_16F_LE		= 0x0000000A,
	kVDPixType_16Fx4_LE		= 0x0000000B,
	kVDPixType_16F_16F_16F_LE	= 0x0000000C,
	kVDPixType_32F_LE		= 0x0000000D,
	kVDPixType_32Fx4_LE		= 0x0000000E,
	kVDPixType_32F_32F_32F_LE	= 0x0000000F,
	kVDPixType_8_8_8		= 0x00000010,
	kVDPixType_B8G8_R8G8	= 0x00000011,		// UYVY
	kVDPixType_G8B8_G8R8	= 0x00000012,		// YUYV
	kVDPixType_V210			= 0x00000013,		// v210 (4:2:2 10 bit)
	kVDPixType_8_B8R8		= 0x00000014,		// NV12
	kVDPixType_B8R8			= 0x00000015,
	kVDPixType_Mask			= 0x0000003F,

	kVDPixSamp_444			= 0x00000040,
	kVDPixSamp_422			= 0x00000080,
	kVDPixSamp_422_JPEG		= 0x000000C0,
	kVDPixSamp_420_MPEG2	= 0x00000100,
	kVDPixSamp_420_MPEG2INT	= 0x00000140,
	kVDPixSamp_420_MPEG1	= 0x00000180,
	kVDPixSamp_420_DVPAL	= 0x000001C0,
	kVDPixSamp_411			= 0x00000200,
	kVDPixSamp_410			= 0x00000240,
	kVDPixSamp_Mask			= 0x00000FC0,
	kVDPixSamp_Bits			= 6,

	kVDPixSpace_Pal			= 0x00001000,
	kVDPixSpace_RGB			= 0x00002000,
	kVDPixSpace_BGR			= 0x00003000,
	kVDPixSpace_BGRA		= 0x00004000,
	kVDPixSpace_Y_601		= 0x00005000,
	kVDPixSpace_Y_709		= 0x00006000,
	kVDPixSpace_YCC_601		= 0x00007000,
	kVDPixSpace_YCC_709		= 0x00008000,
	kVDPixSpace_YCC_JPEG	= 0x00009000,
	kVDPixSpace_Mask		= 0x0003F000,
};

struct VDPixmapSamplingInfo {
	int		mCXOffset16;
	int		mCrYOffset16;
	int		mCbYOffset16;
	int		mCXBits;
	int		mCYBits;
};

uint32 VDPixmapGetFormatTokenFromFormat(int format);
const VDPixmapSamplingInfo& VDPixmapGetSamplingInfo(uint32 samplingToken);

class IVDPixmapGen {
public:
	virtual ~IVDPixmapGen() {}
	virtual void AddWindowRequest(int minY, int maxY) = 0;
	virtual void Start() = 0;
	virtual sint32 GetWidth(int srcIndex) const = 0;
	virtual sint32 GetHeight(int srcIndex) const = 0;
	virtual bool IsStateful() const = 0;
	virtual uint32 GetType(uint32 output) const = 0;
	virtual const void *GetRow(sint32 y, uint32 output) = 0;
	virtual void ProcessRow(void *dst, sint32 y) = 0;
};

class IVDPixmapBlitter {
public:
	virtual ~IVDPixmapBlitter() {}
	virtual void Blit(const VDPixmap& dst, const VDPixmap& src) = 0;
	virtual void Blit(const VDPixmap& dst, const vdrect32 *rDst, const VDPixmap& src) = 0;
};

IVDPixmapBlitter *VDPixmapCreateBlitter(const VDPixmap& dst, const VDPixmap& src);

#endif
