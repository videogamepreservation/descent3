#ifndef PSBITMAP_H
#define PSBITMAP_H
#include "pstypes.h"
#include "CFILE.H"
#ifdef __LINUX__
#include "linux/linux_fix.h" //needed for stricmp's throughout bitmap lib
#endif
#define MAX_BITMAPS 5000
#ifndef MACINTOSH	//DAJ do this in opengl/glide headers
#define NUM_MIP_LEVELS 5
#endif
// It really doesn't matter what these are, as long as its above 10
#define OUTRAGE_4444_COMPRESSED_MIPPED	121
#define OUTRAGE_1555_COMPRESSED_MIPPED	122
#define OUTRAGE_NEW_COMPRESSED_MIPPED	123
#define OUTRAGE_COMPRESSED_MIPPED		124
#define OUTRAGE_COMPRESSED_OGF_8BIT		125
#define OUTRAGE_TGA_TYPE					126
#define OUTRAGE_COMPRESSED_OGF			127
#define BITMAP_NAME_LEN			35
#define BAD_BITMAP_HANDLE	0
// Bitmap flags
#define BF_TRANSPARENT			1
#define BF_CHANGED				2			// this bitmap has changed since last frame (useful for hardware cacheing)
#define BF_MIPMAPPED			4			// This bitmap has mip levels
#define BF_NOT_RESIDENT			8			// This bitmap is not paged in
#define BF_WANTS_MIP			16			// Calculate mip levels when this bitmap is paged in
#define BF_WANTS_4444			32			// Read data as 4444 when this bitmap is paged in
#define BF_BRAND_NEW			64			// This bitmap was just allocated and hasn't been to the video card
#define BF_COMPRESSABLE			128			// This bitmap is compressable for 3dhardware that supports it
// Bitmap priorities
#define BITMAP_FORMAT_STANDARD	0
#define BITMAP_FORMAT_1555			0
#define BITMAP_FORMAT_4444			1
typedef struct
{
	ushort *data16;					// 16bit data
	ushort width,height;			// Width and height in pixels
	ushort used;					// Is this bitmap free to be allocated?

	short cache_slot;					// For use by the rendering lib
	ubyte mip_levels;
	ubyte flags;

	ubyte format;						// See bitmap format types above
	char name[BITMAP_NAME_LEN];	// Whats the name of this bitmap? (ie SteelWall)	
} bms_bitmap;
typedef struct chunked_bitmap
{
	int pw, ph;							// pixel width and height
	int w, h;							// width and height in square bitmaps.
	int *bm_array;						// array of bitmap handles.
}
chunked_bitmap;
extern bms_bitmap GameBitmaps[MAX_BITMAPS];
extern ulong Bitmap_memory_used;
extern ubyte Memory_map[];
// Sets all the bitmaps to unused
void bm_InitBitmaps();
// Frees up all memory used by bitmaps
void bm_ShutdownBitmaps(void);
// Allocs a bitmap of w x h size
// If add_mem is nonzero, adds that to the amount alloced
// (added due to the way the tmapper works)
// Returns bitmap handle if successful, -1 if otherwise
int bm_AllocBitmap (int w,int h,int add_mem);
// Given a handle, frees the bitmap memory and flags this bitmap as unused
void bm_FreeBitmap (int handle);
// Allocs and loads a bitmap
// Loads either regular TGAs or OUTRAGE_TGA_TYPEs
// Returns the handle of the loaded bitmap
// Returns -1 if something is wrong
int bm_AllocLoadFileBitmap (const char *filename,int mipped,int format=BITMAP_FORMAT_1555);
// Allocs and loads a bitmap from an open file
// Returns the handle of the loaded bitmap
// Returns -1 if something is wrong
// If mipped is non-zero, allocs extra space for mips and computes them
int bm_AllocLoadBitmap (CFILE *infile,int mipped,int format=BITMAP_FORMAT_1555);
// Given a handle, makes a big random shape to let you know you are screwed.
void bm_MakeBad (int handle);
// Searches thru all bitmaps for a specific name, returns -1 if not found
// or index of bitmap with name
int bm_FindBitmapName (const char *name);
// Saves a bitmap as an OUTRAGE_TGA_TYPE to an open file
// Returns -1 if something is wrong.
int bm_SaveBitmap (CFILE *fp,int handle);
// Saves a bitmap to a file.  Saves the bitmap as an OUTRAGE_TGA_TYPE.
// Returns -1 if something is wrong.
int bm_SaveFileBitmap (const char *filename,int handle);
// given a handle to a bitmap, returns its width, or -1 if handle is invalid
int bm_w (int handle,int miplevel);
// given a handle to a bitmap, returns its height, or -1 if handle is invalid
int bm_h (int handle,int miplevel);
// given a handle to a bitmap, returns mipped status, or -1 if handle is invalid
int bm_mipped (int handle);
//	a function to determine if a pixel in a bitmap is transparent
bool bm_pixel_transparent(int bm_handle,int x,int y);
//	a function to determine if a pixel in a bitmap is transparent
ushort bm_pixel(int bm_handle,int x,int y);
// given a handle to a bitmap, returns a pointer to its data, or NULL if handle is invalid
ushort *bm_data (int handle,int miplevel);
// Gets bits per pixel for a particular bitmap
// As of 12/30/96 always returns 16
int bm_bpp (int handle);
// Given a source bitmap, generates mipmaps for it
void bm_GenerateMipMaps (int handle);
// Given two bitmaps, scales the data from src to the size of dest
void bm_ScaleBitmapToBitmap (int dest,int src);
// Returns whether or not this bitmap is in use
int bm_used (int n);
// Loads a series of bitmaps from an IFF file
int bm_AllocLoadIFFAnim (const char *filename,int *dest_index,int mipped);
// given a handle and a miplevel, returns the bytes per bitmap row
int bm_rowsize (int handle,int miplevel);
// Goes through the bitmap and sees if there is any transparency...if so, flag it!
int bm_SetBitmapIfTransparent (int handle);
// Saves the passed bitmap handle as a 24 bit uncompressed tga
int bm_SaveBitmapTGA (const char *filename,int handle);
// Sets the bitmap priority.  This comes in handy for our 3d hardware
void bm_set_priority (int handle,int priority);
// Allocs and loads a bitmap but doesn't actually load texel data!
// Returns the handle of the loaded bitmap
// Returns -1 if something is wrong
int bm_AllocLoadFileNoMemBitmap (const char *filename,int mipped,int format=BITMAP_FORMAT_1555);
// Just like bm_AllocBitmap but doesn't actually allocate memory.  Useful for paging!
int bm_AllocNoMemBitmap (int w,int h);
// clears bitmap
void bm_ClearBitmap(int handle);
// Changes the size of a bitmap to a new size
void bm_ChangeSize(int handle,int new_w,int new_h);
void bm_ChangeEndName (const char *src,char *dest);
//	takes a large static bitmap and breaks it into smaller managable bitmaps
bool bm_CreateChunkedBitmap(int bm_handle, chunked_bitmap *chunk);
//	destroys a chunked bitmap.
void bm_DestroyChunkedBitmap(chunked_bitmap *chunk);
//	simply frees up a bitmap
void bm_FreeBitmapData(int handle);
// Returns the format of this bitmap
int bm_format (int handle);
// Returns the number of mipmap levels
int bm_miplevels (int handle);
#endif
