/*
 * $Logfile: /DescentIII/main/descent.cpp $
 * $Revision: 106 $
 * $Date: 3/20/00 12:05p $
 * $Author: Matt $
 *
 * The Descent III main loop
 *
 * $Log: /DescentIII/main/descent.cpp $
 * 
 * 106   3/20/00 12:05p Matt
 * Merge of Duane's post-1.3 changes.
 * Misc Mac stuff, esp. GameRanger (Mac only)
 * 
 * 105   11/04/99 12:35a Chris
 * Added support for Merc
 * 
 * 104   10/27/99 10:26a Matt
 * Fixed bug from Mac merge
 * 
 * 103   10/22/99 10:40p Matt
 * Fixed editing error
 * 
 * 102   10/22/99 1:21p Matt
 * Mac merge
 * 
 * 101   10/12/99 11:00a Jeff
 * added -intro command line parameter to override intro movie filename
 * 
 * 100   8/23/99 5:12p Kevin
 * Proxy support
 * 
 * 99    7/27/99 9:50a Kevin
 * More DVD goodies
 * 
 * 98    7/20/99 12:59p Jason
 * added auto katmai support
 * 
 * 97    7/12/99 6:43p Jeff
 * delete lock file in temp directory after when exiting
 * 
 * 96    6/03/99 8:48a Kevin
 * fixes for new OEM version....
 * 
 * 95    5/21/99 10:05a Kevin
 * Added stuff for a future DVD version
 * 
 * 94    5/13/99 9:46a Kevin
 * duh... not .cpp, .h!
 * 
 * 93    5/13/99 9:34a Kevin
 * call FreeMultiDLL() on quit to delete temp dll files.
 * 
 * 92    5/12/99 2:23p Jeff
 * Descent3 now has a setable temp directory for all temp files
 * 
 * 91    5/10/99 10:21p Ardussi
 * changes to compile on Mac
 * 
 * 90    5/02/99 7:27p Samir
 * a debug option, make it so -moviedir works for the dolby and intro too.
 * 
 * 89    5/01/99 8:17p Jeff
 * ifdef some windows specific code for Linux
 * 
 * 88    4/27/99 9:28p Jason
 * FROM SAMIR: Undid some stuff I broke in the last rev
 * 
 * 87    4/27/99 6:30p Samir
 * play dolby and intro in progression, changed some of the code a bit, it
 * doesn't seem to break anything.
 * 
 * 86    4/27/99 11:38a Kevin
 * added code to play dolby1.mve
 * 
 * 85    4/26/99 11:45a Kevin
 * render a blank screen if prompting for a CD and there is no callback
 * currently
 * 
 * 84    4/25/99 6:14p Kevin
 * added "-timetest file.dem" to behave like gamegauge does
 * 
 * 83    4/25/99 2:19p Kevin
 * main mission voice moved
 * 
 * 82    4/21/99 2:15p Samir
 * table file filter fixes.
 * 
 * 81    4/18/99 4:29p Jeff
 * fixed comparison of string with '\0' instead of NULL
 * 
 * 80    4/18/99 1:56p Kevin
 * Movie player fixes to avoid crashes running under the editor
 * 
 * 79    4/17/99 6:15p Samir
 * replaced gr.h with grdefs.h and fixed resulting compile bugs.
 * 
 * 78    4/17/99 3:44p Kevin
 * Demo2 changes & fixes
 * 
 * 77    4/15/99 9:25a Kevin
 * CD check fixes and updates
 * 
 * 76    4/14/99 3:07p Kevin
 * Force main mission to list even on small installations
 * 
 * 75    4/14/99 2:50a Jeff
 * fixed some case mismatched #includes
 * 
 * 74    4/13/99 3:30p Samir
 * changed call SetScreenMode(SM_CINEMATIC) to SM_MENU so UI works when
 * the game starts.
 * 
 * 73    4/09/99 2:38p Kevin
 * Changed where on the CD D3 will look for files
 * 
 * 72    4/02/99 7:04p Kevin
 * Added splash screens do release builds
 * 
 * 71    4/02/99 5:08p Matt
 * Added intro movie.
 * 
 * 70    3/31/99 3:04p Jeff
 * added _real_ temporary credits system...
 * 
 * 69    3/29/99 7:29p Jason
 * made renderer handle default resolution more gracefully
 * 
 * 68    3/22/99 6:26p Matt
 * Cleaned up error handling in cfile and editor level loads.
 * 
 * 67    3/19/99 4:08p Kevin
 * Multiple CD installation support
 * 
 * 66    3/18/99 2:33p Jeff
 * fixed bug clearing the Current pilot stuff before we were done using it
 * 
 * 65    3/15/99 4:32p Jeff
 * fixed 'fake' memory leak with Current pilot
 * 
 * 64    3/11/99 5:02p Samir
 * set ui screen mode after showing static screen.
 * 
 * 63    3/08/99 3:59p Kevin
 * Idle processing of network packets fixed
 * 
 * 62    3/01/99 9:51p Jeff
 * fixed bad prototype
 * 
 * 61    3/01/99 9:03p Kevin
 * OEM Beta 4
 * 
 * 60    2/26/99 2:11a Samir
 * do render GameFrame with app not active.
 * 
 * 59    2/25/99 8:54p Jeff
 * Inventory supports level change persistant items.  Inventory supports
 * time-out objects.  Inventory Reset changed (takes a level of reset
 * now).  Quad lasers stay across level change (single player).  Guidebot
 * bug fixed (now back in ship on level start).  Quads time out when
 * spewed.  Invulnerability and cloak powerups no longer use game
 * event/ms, so they can be saved in game saves (moved to
 * MakePlayerInvulnerable and MakeObjectInvisible)
 * 
 * 58    2/21/99 6:38p Samir
 * mouse and key input better. buffered mouse.
 * 
 * 57    2/20/99 2:31p Kevin
 * Made multiplayer DLLs return to the game list after a game.
 * 
 * 56    2/13/99 12:32a Jeff
 * inventory reset takes a different parameter
 * 
 * 55    2/10/99 4:38p Matt
 * Misc. changes for table file parsing
 * 
 * 54    2/09/99 1:29a Jeff
 * added code to let D3 process multiplayer games in the background if
 * game is not in focus.
 * 
 * 53    2/05/99 7:23p Kevin
 * OEM Changes
 * 
 * 52    2/04/99 9:46a Kevin
 * OEM version changes
 * 
 * 51    1/15/99 7:16p Kevin
 * Added GameGauge Configuration & code
 * 
 * 50    12/03/98 10:23a Jason
 * fixed black background problem with D3D
 * 
 * 49    10/28/98 4:48p Kevin
 * Cleaned up inventory usage
 * 
 * 48    10/28/98 12:27p Kevin
 * Shutdown sound system when quiting
 * 
 * 47    10/24/98 2:16p Samir
 * moved pollcontrols to controls.cpp, readplayercontrols.
 * 
 * 46    10/23/98 1:09p Samir
 * Demo Release 1.0
 * 
 * 45    10/20/98 6:34p Jeff
 * changes made to get dedicated server working
 * 
 * 44    10/18/98 11:40p Matt
 * Generalized the function that puts up the upsell screen so the credits
 * could use it.
 * 
 * 43    10/16/98 1:54p Kevin
 * Changes for Demo Beta 4
 * 
 * 42    10/16/98 12:17p Samir
 * took out ddio_KeyFrame.
 * 
 * 41    10/14/98 4:37p Matt
 * Made InitD3System() exit with error if there's a problem instead of
 * returning a status value.  Also moved some editor-specific code from
 * init.cpp to mainfrm.cpp, and cleaned up some other initialization and
 * error-handling code.
 * 
 * 40    10/12/98 4:40p Samir
 * mouse click to leave upsell screen.
 * 
 * 39    10/12/98 1:46p Samir
 * new Program_version parameters.
 * 
 * 38    10/08/98 7:52p Samir
 * added upsell screen.
 * 
 * 37    10/08/98 7:46p Samir
 * added demo upsell screen.
 * 
 * 36    10/08/98 7:26p Samir
 * changed the prototype for the defer handler callback.
 * 
 * 35    10/08/98 12:00p Kevin
 * Demo system work
 * 
 * 34    10/02/98 12:30p Samir
 * added version information for beta/demo.
 * 
 * 33    9/18/98 1:27p Jason
 * cleaned up renderer initting
 * 
 * 32    9/15/98 4:31p Jason
 * added more functionality for the dedicated server
 * 
 * 31    9/15/98 12:42p Jason
 * got dedicated server actually working
 * 
 * 30    9/14/98 6:28p Jason
 * first pass at getting dedicated server working
 * 
 * 29    8/20/98 10:51a Samir
 * added the RESTORE_GAME_MODE function mode,.
 * 
 * 28    7/21/98 6:50p Jeff
 * don't initialize or close renderer if set screen mode hasn't been
 * called yet in debug handlers.
 * 
 * 27    7/01/98 4:56p Samir
 * redid init code.
 * 
 * 26    6/16/98 10:38a Jeff
 * localization, strings pulled out to stringtable.h and d3.str
 * 
 * 25    4/27/98 7:24p Samir
 * poll controller at specified rate.
 * 
 * 24    3/23/98 8:03p Samir
 * A bunch of changes to allow for ALT-TAB to work.
 * 
 * 23    3/19/98 11:27a Samir
 * Better error checking.
 * 
 * 22    3/10/98 5:16p Samir
 * Got debug callbacks working when you hit an Int3.
 * 
 * 21    2/26/98 1:00p Samir
 * input only when app is active.
 * 
 * 20    2/23/98 4:46p Jeff
 * Moved serialization check to Winmain
 * 
 * 19    2/15/98 7:44p Matt
 * Added groovy try/catch/throw error checking for cfile functions
 * 
 * 18    2/08/98 5:01p Samir
 * New game sequencing changes.
 * 
 * 17    2/07/98 6:33p Jeff
 * Added in serialization check
 * 
 * 16    2/02/98 7:35p Samir
 * Call QuickPlayGame to play game using quick mission system.
 * 
 * 15    1/10/98 2:55p Jason
 * changed some things for multiplayer
 * 
 * 14    1/07/98 3:49p Jason
 * only call StartNewGame if not in multiplayer
 * 
 * 13    12/29/97 5:44p Samir
 * Took out references to grViewport and old 2d library.
 * 
 * 12    12/03/97 7:34p Samir
 * Run controller poll in idle loop.
 * 
 * 11    10/27/97 4:30p Samir
 * Set screen mode to SM_NULL when done with game.
 * 
 * 10    10/16/97 2:30p Samir
 * Added defer handler.
 * 
 * 9     10/02/97 12:36p Samir
 * Redid game sequencing flow.
 * 
 * 8     9/17/97 11:16a Samir
 * BIG SEGMENT RIPOUT.
 * 
 * 7     9/12/97 4:08p Samir
 * Made sure main game program version is DEVELOPMENT, not FULL
 * DEVELOPMENT.
 * 
 * 6     8/28/97 6:13p Matt
 * Set the room engine to be always on
 * 
 * 5     8/12/97 3:21p Samir
 * When entering game from editor, call the QuickStart functions to load
 * scripts, etc.
 * 
 * 4     7/24/97 2:55p Matt
 * Save game settings to registry on game exit
 * 
 * 10    6/11/97 1:07p Samir
 * The removal of gameos and replaced with oeApplication, oeDatabase
 * 
 * 9     5/15/97 2:04p Samir
 * Created functions to create game viewport.
 * 
 * 8     3/10/97 11:30a Samir
 * Took out osDebug global
 * 
 * 7     3/03/97 5:23p Samir
 * Added OS_database, and OS_debug objects pointers.
 * 
 * 6     2/26/97 6:10 PM Jeremy
 * removed #include of <windows.h>
 * 
 * 5     2/04/97 5:28p Samir
 * Added EDITOR_GAME_MODE mode
 * 
 * 4     2/04/97 2:32p Samir
 * Added a menu mode
 * 
 * 3     1/30/97 6:20p Samir
 * Mainloop was altered a little, and some changes reflecting osObject
 * fix.
 *
 * $NoKeywords: $
 */
#include <stdlib.h>

#include "pserror.h"
#include "grdefs.h"
#include "mono.h"
#include "CFILE.H"

#include "init.h"
#include "game.h"
#include "program.h"
#include "descent.h"
#include "menu.h"
#include "Mission.h"
#include "ddio.h"
#include "controls.h"
#include "Controller.h"
#include "gamesequence.h"
#include "stringtable.h"
#include "dedicated_server.h"
#include "networking.h"
#include "hlsoundlib.h"
#include "player.h"
#include "pilot.h"
#include "newui.h"
#include "credits.h"
#include "cinematics.h"
#include "args.h"
#include "multi_dll_mgr.h"
#include "localization.h"
#include "mem.h"
#if defined(MACINTOSH) && defined (GAMERANGER)
#include "GameRanger.h"
#endif
//	---------------------------------------------------------------------------
//	Variables
//	---------------------------------------------------------------------------
#ifdef EDITOR
static function_mode Function_mode = EDITOR_MODE;	// Game function mode
#else
static function_mode Function_mode = INIT_MODE;		// Game function mode
#endif
static function_mode Last_function_mode = INIT_MODE;

grScreen *Game_screen = NULL;			// The one and only video screen
oeApplication *Descent = NULL;		// The Main application
oeAppDatabase *Database = NULL;		// Application database.

bool Descent_overrided_intro = false;

extern bool Game_gauge_do_time_test;
bool Katmai=true;

char Descent3_temp_directory[_MAX_PATH];	//temp directory to put temp files
//	---------------------------------------------------------------------------
//	Descent3: Choke 1
//		Initializes game elements and invokes the MainLoop
//	---------------------------------------------------------------------------
//#define BETA

#if (defined(OEM) || defined(DEMO))
void ShowStaticScreen(char *bitmap_filename,bool timed=false,float delay_time=0.0f);
#endif

extern int CD_inserted;

char Proxy_server[200] = "";
short Proxy_port=80;

void Descent3()
{
	int type;

#ifdef _DEBUG
	type = DEVELOPMENT_VERSION;
#else 
	type = RELEASE_VERSION;
#endif
#ifdef BETA
	type |= BETA_VERSION;
#endif
#ifdef DEMO
	type |= DEMO_VERSION;
#endif

	ProgramVersion(type, D3_MAJORVER, D3_MINORVER, D3_BUILD);

	//Catch cfile errors
	try
	{
		//Init a bunch of stuff
		InitD3Systems1(false);

		int proxyarg = FindArg("-httpproxy");
		if(proxyarg)
		{
			strcpy(Proxy_server,GameArgs[proxyarg+1]);

			char *port = strchr(Proxy_server,':');
			if(port)
			{
				//terminate the hostname
				*port = 0;
				//Increment to the first character of the port name
				port++;					
				//get the port number
				Proxy_port = atoi(port);
			}

		}
		//Show intro & loading screens if not dedicated server
		if (!Dedicated_server)
		{
			SetScreenMode(SM_CINEMATIC);

		//Show the intro movie
			if (! FindArg("-nointro")) {
				char intropath[_MAX_PATH*2];
				bool remote_path =  (CD_inserted==1) ? true : false;

			#ifdef _DEBUG
				if (FindArg("-moviedir")) {
					remote_path = true;
				}
			#endif

		  		ddio_MakePath(intropath,Base_directory,"movies","dolby1.mv8",NULL);

				if(remote_path || (cfexist(intropath)))
				{
					char *t = GetMultiCDPath("dolby1.mv8");
					if (t)
						PlayMovie(t);
				}

				int intro_movie_arg;
				char base_intro_movie_name[256];
				char *intro_movie_name;
				
				intro_movie_arg = FindArg("-intro");
				if(intro_movie_arg>0)
				{
					// we have an override for the intro movie
					// we have to split path because the stupid args system of D3
					// capitalizes everything and the PlayMovie function expects
					// a lowercase extension
					char extension[16],*p;
					p = extension;
					ddio_SplitPath(GameArgs[intro_movie_arg+1],NULL,base_intro_movie_name,extension);
					while(*p) { *p = tolower(*p); p++;}
					strcat(base_intro_movie_name,extension);
					
					Descent_overrided_intro = true;

					intro_movie_name = base_intro_movie_name;
				}else
				{
					strcpy(base_intro_movie_name,"intro.mve");
					intro_movie_name = base_intro_movie_name;
				}

				ddio_MakePath(intropath,Base_directory,"movies",intro_movie_name,NULL);

				if(remote_path || (cfexist(intropath)))
				{
					char *t = GetMultiCDPath(intro_movie_name);
					if (t)
						PlayMovie(t);
				}
			}

			SetScreenMode(SM_MENU);
			//Show the intro screen
			IntroScreen();
		}

		//Init a bunch more stuff
		InitD3Systems2(false);

		#ifdef GAMEGAUGE
		if(0)
		#else
		if(!Game_gauge_do_time_test)
		#endif
		{
			SetFunctionMode(MENU_MODE);
		}
		else
		{
			SetFunctionMode(GAMEGAUGE_MODE);
		}

#if defined(MACINTOSH) && defined (GAMERANGER)
		if(GRCheckFileForCmd()) {
			SetFunctionMode (GAME_MODE);
			GRGetWaitingCmd();
		}
#endif
		MainLoop();

		//delete the lock file in the temp directory (as long as it belongs to us)
		ddio_DeleteLockFile(Descent3_temp_directory);

		//Save settings to registry
		SaveGameSettings();
	}
	catch(cfile_error *cfe) {
		Error(TXT_D3ERROR1,(cfe->read_write==CFE_READING)?TXT_READING:TXT_WRITING,cfe->file->name,cfe->msg);
	}
}

//	---------------------------------------------------------------------------
//	Main Loop: Choke 1 from editor Choke 2 from Game
//		If called from the editor, this is the best way to start up the game.
//		Otherwise this should be called from the main function.
//	---------------------------------------------------------------------------

//#ifdef GAMEGAUGE
extern int frames_one_second;
extern int min_one_second;
extern int max_one_second;
extern float gamegauge_start_time;
extern int gamegauge_total_frames;
extern float gamegauge_total_time;
extern short gamegauge_fpslog[GAMEGAUGE_MAX_LOG];

//#endif

void MainLoop()
{
	int exit_game = 0;

	while (!exit_game)
	{
		if (Dedicated_server && !(Function_mode==GAME_MODE || Function_mode==QUIT_MODE))
			SetFunctionMode (GAME_MODE);
					
		switch(Function_mode)
		{
			case QUIT_MODE:
				exit_game=1;
				break;
			case MENU_MODE:
				exit_game = MainMenu();
				break;
			case RESTORE_GAME_MODE:				// do special sequencing for load games.
				SetGameState(GAMESTATE_LOADGAME);
				PlayGame();
				break;

			case GAME_MODE:
				SetGameState(GAMESTATE_NEW);
				PlayGame();							// Does what is says.
				break;
			case LOADDEMO_MODE:
				SetGameState(GAMESTATE_LOADDEMO);
				PlayGame();
				break;
			case CREDITS_MODE:
				Credits_Display();
				Function_mode = MENU_MODE;
				break;
//#ifdef GAMEGAUGE
			case GAMEGAUGE_MODE:
				{
					int c;
					for(c=0;c<GAMEGAUGE_MAX_LOG;c++)
						gamegauge_fpslog[c] = 0;
					SetGameState(GAMESTATE_GAMEGAUGEDEMO);
					PlayGame();
					//exit_game = 1;
				}
				break;
//#endif
		#ifdef EDITOR
			case EDITOR_GAME_MODE:				// run level and then instead of menus, go to editor.
				QuickPlayGame();
				Function_mode = EDITOR_MODE;
				break;
			case EDITOR_MODE:
				SetScreenMode(SM_NULL);
				exit_game = 1;						// this MainLoop call should be issued from editor, so
														// this should just return to the editor
				break;
		#endif

			default:
				Int3();								// Bogus function mode
		}
	}
	//Clean up these items so we don't report them as leaked memory
	Sound_system.KillSoundLib(true);
	for(int a=0;a<MAX_PLAYERS;a++)
	{
		Players[a].inventory.Reset(false,INVRESET_ALL);
		Players[a].counter_measures.Reset(false,INVRESET_ALL);
	}
	
#ifdef GAMEGAUGE
	if(1)
#else
	if(Game_gauge_do_time_test)
#endif
	{
		char fpsfile[_MAX_PATH*2];
		CFILE *cfp;
		ddio_MakePath(fpsfile,Base_directory,"fps.txt",NULL);
		cfp = cfopen(fpsfile,"wt");
		if(cfp)
		{
			char szline[200];
			sprintf(szline,"%.2f Descent3 v%d.%d",gamegauge_total_frames/gamegauge_total_time,(int)Program_version.major,(int)Program_version.minor);
			cf_WriteString(cfp,szline);
			sprintf(szline,"%d Min",min_one_second);
			cf_WriteString(cfp,szline);
			sprintf(szline,"%d Max",max_one_second);
			cf_WriteString(cfp,szline);
			for(int b=1;((b<GAMEGAUGE_MAX_LOG)&&(gamegauge_fpslog[b]));b++)
			{
				sprintf(szline,"%d Second %d",gamegauge_fpslog[b],b);
				cf_WriteString(cfp,szline);
			}
			
			cfclose(cfp);
		}
	}
#if defined(OEM) 
	if(!Dedicated_server)
		ShowStaticScreen("oemupsell.ogf");
#elif defined(DEMO)
	if(!Dedicated_server)
		ShowStaticScreen("upsell.ogf");
#endif
	FreeMultiDLL();
	SetScreenMode(SM_NULL);
}

#if (defined(OEM) || defined(DEMO) || defined(RELEASE))
//Shows a fullscreen static bitmap
void ShowStaticScreen(char *bitmap_filename,bool timed,float delay_time)
{
	extern void ui_SetScreenMode(int w, int h);
	chunked_bitmap splash_bm;

// do splash screen on release
	int bm_handle = bm_AllocLoadFileBitmap(IGNORE_TABLE(bitmap_filename),0);

	ddio_KeyFlush();
	ddio_MouseReset();

	if (bm_handle > -1) {
		if (!bm_CreateChunkedBitmap(bm_handle, &splash_bm)) 
			Error("Failed to slice up %s.",bitmap_filename);

		bm_FreeBitmap(bm_handle);
		float start_time = timer_GetTime();
		while (1)
		{
			StartFrame();
			
			rend_DrawChunkedBitmap(&splash_bm, 0,0,255);
			rend_Flip();
			EndFrame();

			
			Descent->defer();

			if(!timed)
			{
				int key = ddio_KeyInKey();
				if (key == KEY_ENTER || key == KEY_SPACEBAR || key == KEY_ESC) 
					break;

				int x,y,dx,dy;
				if (ddio_MouseGetState(&x,&y,&dx,&dy))
					break;
			}
			else
			{
				if((timer_GetTime()-start_time)>delay_time)
				{
					break;
				}

			}
		}

		bm_DestroyChunkedBitmap(&splash_bm);
	}
	else {
		mprintf((0, "Couldn't load %s.\n",bitmap_filename));
	}

	ui_SetScreenMode(Max_window_w, Max_window_h);
}
#endif



//	---------------------------------------------------------------------------
//	Accessor functions
//	---------------------------------------------------------------------------

void SetFunctionMode(function_mode mode)
{
	Last_function_mode = Function_mode;
	Function_mode = mode;
}


function_mode GetFunctionMode()
{
	return Function_mode;
}


//	---------------------------------------------------------------------------
// The game's defer handler (For Win32, it happens during idle processing) 
//	---------------------------------------------------------------------------
extern bool Skip_render_game_frame;
void GameFrame(void);
void D3DeferHandler(bool is_active)
{
	if (is_active) {
	// perform any needed io system processing in the background
		ddio_Frame();
	}
	else {
	//JEFF - If the game is in idle loop and we are in multiplayer game
	//then process the game frame so we stay alive in the game.  
		if(Game_mode&GM_MULTI) {
			Skip_render_game_frame = true;
			GameFrame();
			Skip_render_game_frame = false;
		}
	}

	//JEFF - Commented out due to new idle processing
	nw_DoNetworkIdle();
}


//	---------------------------------------------------------------------------
//	this is called when you hit a debug break!
//	---------------------------------------------------------------------------
#ifndef RELEASE
#include "debug.h"
#include "renderer.h"
extern int rend_initted;			// from game.cpp

void D3DebugStopHandler()
{
//	close off all systems for debugging.
	if (rend_initted) {
		rend_Close();
	}
}


void D3DebugResumeHandler()
{
//	reopen all systems for gameplay.
	if (rend_initted) 
		rend_initted = rend_Init (PreferredRenderer, Descent,&Render_preferred_state);
	
	if (rend_initted!=0)
		rend_initted=1;	
}

#endif

void RenderBlankScreen(void);

char * GetCDVolume(int cd_num)
{
	char *p = NULL;

#if defined (MACINTOSH)
	char volume_labels[3][_MAX_PATH] = {"","Descent3","Descent3"};
#elif !defined (OEM)
	char volume_labels[3][_MAX_PATH] = {"","D3_1","D3_2"};
#else
	char volume_labels[3][_MAX_PATH] = {"","D3OEM_1",""};
#endif

	p = ddio_GetCDDrive("D3_DVD");

	if(!p)
		p = ddio_GetCDDrive(volume_labels[cd_num]);

	if(p)
	{
		//We've got the disk already in the drive!
		return p;
	}
	else
	{
		//Don't prompt for CD if not a release build
		#ifndef RELEASE
		//return NULL;
		#endif

		//prompt them to enter the disk...
		do
		{
			char message_txt[50];
#ifdef MACINTOSH
			strcpy(message_txt,TXT_CDPROMPT);
			message_txt[strlen(message_txt)-2] = '\0';
#else
			sprintf(message_txt,TXT_CDPROMPT,cd_num);
#endif
			//We need a background drawn!
#if defined(LINUX)
			void (*ui_cb)() = GetUICallback();
#else
			void *ui_cb = GetUICallback();
#endif
			if(ui_cb==NULL)
				SetUICallback(RenderBlankScreen);
			int res = DoMessageBox(PRODUCT_NAME,message_txt,MSGBOX_OKCANCEL,UICOL_WINDOW_TITLE,UICOL_TEXT_NORMAL);		
			SetUICallback((void (*)(void))ui_cb);
			//
			if(res == 0)
			{
				return NULL;
			}
			p = ddio_GetCDDrive(volume_labels[cd_num]);
			if(p && *p)
				return p;
		}while(!(p && *p));
		
		return NULL;
	}

}

typedef struct file_vols
{
	char file[_MAX_PATH];
	char localpath[_MAX_PATH*2];
	int volume;
	bool localized;
}file_vols;

extern int CD_inserted;

//Localization_GetLanguage();


char Oem_language_dirs[5][10] = 
{
	"English",
	"German",
	"Spanish",
	"Italian",
	"French"
};


file_vols file_volumes[] = 
{
	//Filename, directory it might be installed on the hard drive, CD number to look for it
	{"d3.mn3","missions",1,false},
	{"d3_2.mn3","missions",2,false},
	{"level1.mve","movies",1,true},
	{"level5.mve","movies",2,true},
	{"end.mve","movies",2,true},
	{"intro.mve","movies",1,true},
#ifdef MACINTOSH
	{"ppics.hog","missions",1,true},
	{"training.mn3","missions",1,true},
#else
	{"dolby1.mv8","movies",1,true},
#endif
	{"d3voice1.hog","missions",1,true},
	{"d3voice2.hog","missions",2,true}
};

int num_cd_files = sizeof(file_volumes)/sizeof(file_vols);

//This function figures out whether or not a file needs to be loaded off of
//CD or off of the local drive. If it needs to come from a CD, it figures out
//which CD and prompts the user to enter that CD. If they hit cancel, it 
//returns NULL.
char * GetMultiCDPath(char *file)
{
	static char filepath[_MAX_PATH*2];
	static char fullpath[_MAX_PATH*2];
	int volume = 0;
	int i;
	
	if(file==NULL)
		return NULL;
	if(*file=='\0')
		return NULL;

	// see if there is a command line override for the name of the intro movie
	int intro_movie_arg = FindArg("-intro");
	char temp_filename[256];
	
	//Clear out any old path
	//memset(filepath,0,_MAX_PATH*2);
	filepath[0] = NULL;
	
	for(i=0;i<num_cd_files;i++)
	{
		char *vol_filename;
		vol_filename = file_volumes[i].file;

		// check to see if we need to override this string (for intro movie)
		if(intro_movie_arg>0 && !stricmp(vol_filename,"intro.mve"))
		{
			// we have to override this intro movie
			char extension[16],*p;
			p = extension;
			ddio_SplitPath(GameArgs[intro_movie_arg+1],NULL,temp_filename,extension);
			while(*p) { *p = tolower(*p); p++;}
			strcat(temp_filename,extension);
			vol_filename = temp_filename;
		}

		if(strcmpi(vol_filename,file)==0)
		{
			volume = file_volumes[i].volume;			
			ddio_MakePath(fullpath,LocalD3Dir,file_volumes[i].localpath,file,NULL);
			//See if the file is in the local dir already.
			if(cfexist(fullpath))
			{
				return fullpath;
			}
		#ifdef _DEBUG
			else if (strcmpi(file_volumes[i].localpath, "movies")==0) {
			// if one specified a directory where the movies are located.
				int arg = FindArg("-moviedir");
				if (arg) {
					ddio_MakePath(fullpath, GameArgs[arg+1], file, NULL);
					return fullpath;
				}
			}
		#endif
			break;
		}
	}
	//This is a file we don't know about
	if(i==num_cd_files)
		return file;

	if(volume)
	{
		char *p = GetCDVolume(volume);
		if(p)
		{
			//If it's DVD, we need to get the proper files for the language
			if( (CD_inserted==3)&&(file_volumes[i].localized) )
			{
				ddio_MakePath(filepath,p,file_volumes[i].localpath,Oem_language_dirs[Localization_GetLanguage()],file,NULL);
			}
			else
			{
				ddio_MakePath(filepath,p,file_volumes[i].localpath,file,NULL);
			}
			//strcpy(filepath,p);
			//strcat(filepath,file);
			return filepath;
		}
		else
		{
			return NULL;
		}		
	}

	return NULL;
}
