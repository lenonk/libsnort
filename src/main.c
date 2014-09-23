extern int snort_argc;
extern char **snort_argv;

/*
 *
 * Function: main(int, char *)
 *
 * Purpose:  Handle program entry and exit, call main prog sections
 *           This can handle both regular (command-line) style
 *           startup, as well as Win32 Service style startup.
 *
 * Arguments: See command line args in README file
 *
 * Returns: 0 => normal exit, 1 => exit on error
 *
 */
int main(int argc, char *argv[])
{
#if defined(WIN32) && defined(ENABLE_WIN32_SERVICE)
    /* Do some sanity checking, because some people seem to forget to
     * put spaces between their parameters
     */
    if ((argc > 1) &&
        ((_stricmp(argv[1], (SERVICE_CMDLINE_PARAM SERVICE_INSTALL_CMDLINE_PARAM)) == 0) ||
         (_stricmp(argv[1], (SERVICE_CMDLINE_PARAM SERVICE_UNINSTALL_CMDLINE_PARAM)) == 0) ||
         (_stricmp(argv[1], (SERVICE_CMDLINE_PARAM SERVICE_SHOW_CMDLINE_PARAM)) == 0)))
    {
        FatalError("You must have a space after the '%s' command-line parameter\n",
                   SERVICE_CMDLINE_PARAM);
    }

    /* If the first parameter is "/SERVICE", then start Snort as a Win32 service */
    if((argc > 1) && (_stricmp(argv[1],SERVICE_CMDLINE_PARAM) == 0))
    {
        return SnortServiceMain(argc, argv);
    }
#endif /* WIN32 && ENABLE_WIN32_SERVICE */

    snort_argc = argc;
    snort_argv = argv;

    return SnortMain(argc, argv);
}
