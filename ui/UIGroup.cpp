/*
* $Logfile: /DescentIII/Main/ui/UIGroup.cpp $
* $Revision: 6 $
* $Date: 4/14/99 1:53a $
* $Author: Jeff $
*
* Group box
*
* $Log: /DescentIII/Main/ui/UIGroup.cpp $
 * 
 * 6     4/14/99 1:53a Jeff
 * fixed case mismatched #includes
 * 
 * 5     10/20/98 12:14p Jeff
 * added color to the UIGroup
 * 
 * 4     10/16/98 1:42p Jeff
 * updated UIGroup
 * 
 * 3     10/12/98 11:30a Kevin
 * More memory stuff
 * 
 * 2     10/07/98 11:25a Jeff
 * created UIGroup
*
* $NoKeywords: $
*/



#include "UIlib.h"
#include <string.h>
#if defined(MACOSX)
#include <malloc/malloc.h>
#else
#include <malloc.h>
#endif
#include "mem.h"

//	----------------------------------------------------------------------------
//	UIGroup
//		Draws a group box on to the window

UIGroup::UIGroup()
{
	m_Label = NULL;
	m_bTextCreated = false;
}

UIGroup::~UIGroup()
{
}

void UIGroup::Create(UIWindow *parent, char *label, int x, int y, int w, int h, ddgr_color label_color,ddgr_color box_color,int flags)
{
	ASSERT(parent);
	ASSERT(label);

	m_LabelColor = label_color;
	m_BoxColor = box_color;	

	UIStatic::Create(parent,NULL,x,y,w,h,flags);

	int length = strlen(label);
	if(length){
		m_Label = (char *)mem_malloc(length+1);
		strcpy(m_Label,label);
	}
}

void UIGroup::OnDraw()
{
	ui_DrawSetAlpha(255);

	int text_height = 0;
	int text_width = 0;

	if(m_Label){
		text_height = ui_GetTextHeight("X")/2;
		text_width = ui_GetTextWidth(m_Label);
	}

	ui_DrawLine(m_BoxColor,0,text_height,0,m_H-1);				//left side
	ui_DrawLine(m_BoxColor,0,m_H-1,m_W-1,m_H-1);					//bottom
	ui_DrawLine(m_BoxColor,m_W-1,m_H-1,m_W-1,text_height);		//right side

	int top_edge_length = 0;

	top_edge_length = (m_W - text_width) / 2;
	if(m_Label)
		top_edge_length -= 3;

	if(top_edge_length < 0 )
		top_edge_length = 0;

	ui_DrawLine(m_BoxColor,0,text_height,top_edge_length,text_height);
	ui_DrawLine(m_BoxColor,m_W,text_height,m_W - top_edge_length,text_height);

	if(!m_bTextCreated){
		m_bTextCreated = true;		
		m_tLabel.Create(m_Wnd,&UITextItem((m_Label)?m_Label:"",m_LabelColor),m_X + top_edge_length + 3,m_Y);
	}
}

void UIGroup::OnDestroy()
{
	if(m_Label)
		mem_free(m_Label);
}
