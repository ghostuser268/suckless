static const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#101010", /* black   */
  [1] = "#7c7c7c", /* red     */
  [2] = "#8e8e8e", /* green   */
  [3] = "#a0a0a0", /* yellow  */
  [4] = "#686868", /* blue    */
  [5] = "#747474", /* magenta */
  [6] = "#868686", /* cyan    */
  [7] = "#b9b9b9", /* white   */

  /* 8 bright colors */
  [8]  = "#525252", /* black   */
  [9]  = "#7c7c7c", /* red     */
  [10] = "#8e8e8e", /* green   */
  [11] = "#a0a0a0", /* yellow  */
  [12] = "#686868", /* blue    */
  [13] = "#747474", /* magenta */
  [14] = "#868686", /* cyan    */
  [15] = "#005950", /* white   */
  /* special colors */
  [256] = "#000000", /* background */
  //[256] = "#192428", [> background <]
  [257] = "#c0c5ce", /* foreground */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor
 */
 unsigned int defaultfg = 257;
 unsigned int defaultbg = 256;
 unsigned int defaultcs = 257;
 unsigned int defaultrcs= 258;

/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
 */
static unsigned int defaultitalic = 7;
static unsigned int defaultunderline = 7;

