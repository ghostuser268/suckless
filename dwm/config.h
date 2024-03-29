/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int gappx = 30;
static const unsigned int snap = 0; /* snap pixel */
static const int showbar = 1;       /* 0 means no bar */
static const int topbar = 1;        /* 0 means bottom bar */
static const int usealtbar = 0;

static const char *altbarclass = "";
static const char *altbarcmd = "";

// POLYBAR
// static const char *altbarclass = "Polybar";
// static const char *altbarcmd = "$HOME/personal/confs/polybar/launch.sh";

// LEMONBAR
// static const char *altbarclass = "Lemonbar";
// static const char *altbarcmd =
//"${HOME}/personal/suckless/bars/lemonbar/test.sh | lemonbar -dbp";

static const int bar_padding = 5;

static const unsigned int baralpha = 0xff;
static const unsigned int borderalpha = OPAQUE;

static const int user_bh = 5;
static const int vertpad = 0;      /* vertical padding of bar */
static const int sidepad = 0;      /* horizontal padding of bar */
static const int horizpadbar = 10; /* horizontal padding for statusbar */
static const int vertpadbar = 40;  /* vertical padding for statusbar */

static const char *fonts[] = {
    "Iosevka Orw,Iosevka Orw Medium Oblique:style Font: size=10"};
static const char dmenufont[] =
    "Iosevka Orw,Iosevka Orw Medium Oblique:style Font: size=29";
// Iosevka Orw,Iosevka Orw Medium Oblique:style
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {"#ffffff", "#000000", "#000000"},
    [SchemeSel] = {"#ffffff", "#000000", "#ffffff"},
};

static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};
/* tagging */
static const char *tags[] = {"I", "II", "III", "IV"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"mpv", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = {"dmenu_run", "-m",  dmenumon, "-fn",
                                 dmenufont,   "-nb", NULL};
static const char *termcmd[] = {"st", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_q, killclient, {0}},
    {MODKEY | ShiftMask, XK_c, quit, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_g, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},

    {MODKEY, XK_Left, focusmon, {.i = -1}},
    {MODKEY, XK_Right, focusmon, {.i = +1}},
    {MODKEY, XK_Up, focusstack, {.i = -1}},
    {MODKEY, XK_Down, focusstack, {.i = +1}},

    {MODKEY | ShiftMask, XK_Left, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_Right, tagmon, {.i = +1}},
    {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_equal, setgaps, {.i = +1}},
    {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
    {MODKEY, XK_Return, spawn, SHCMD("st")},
    {MODKEY, XK_p, spawn, SHCMD("st -e tmux")},
    {MODKEY, XK_F1, spawn,
     SHCMD("xbacklight -dec 10;kill -35 $(pidof dwmblocks)")},

    {MODKEY, XK_F2, spawn,
     SHCMD("xbacklight -inc 10;kill -35 $(pidof dwmblocks)")},

    {MODKEY, XK_F6, spawn,
     SHCMD(
         "amixer -qc 1 set Master 5%\\+ unmute; kill -44 $(pidof dwmblocks)")},
    {MODKEY, XK_F5, spawn,
     SHCMD(
         "amixer -qc 1 set Master 5%\\- unmute; kill -44 $(pidof dwmblocks)")},
    {MODKEY, XK_F4, spawn, SHCMD("amixer -qc 1 set Master toggle;")},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    //{ClkStatusText, 0, Button1, spawn, {.v = termcmd}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkStatusText, 0, Button3, spawn, SHCMD("st -e btop")},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
    IPCCOMMAND(view, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(toggleview, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(tag, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(toggletag, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(tagmon, 1, {ARG_TYPE_UINT}),
    IPCCOMMAND(focusmon, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(focusstack, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(zoom, 1, {ARG_TYPE_NONE}),
    IPCCOMMAND(incnmaster, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(killclient, 1, {ARG_TYPE_SINT}),
    IPCCOMMAND(togglefloating, 1, {ARG_TYPE_NONE}),
    IPCCOMMAND(setmfact, 1, {ARG_TYPE_FLOAT}),
    IPCCOMMAND(setlayoutsafe, 1, {ARG_TYPE_PTR}),
    IPCCOMMAND(quit, 1, {ARG_TYPE_NONE})};
