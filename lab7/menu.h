/*Copyright qcc                                                                                  */
/*FILENAME Menu.h                                                                                */
/*authort qcc                                                                                    */
/*time:2017-11-06                                                                                */
/*Description: menu.c for lab7                                                                   */


int MenuConfig(char * cmd, char * desc, int (*handler)(int argc, char *argv[]));
int ExcuteMenu();
