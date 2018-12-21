package mp4converter;

import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.logging.Logger;


/**
 * Deze klasse bevat de main methode van de applicatie.
 */
public class MP4Converter {

    // De volgende static variabelen zijn voorgedefinieërde error waarden
    private static final int ERR_ARG_COUNT = 1;
    private static final int ERR_FILE_NOT_EXISTS = 2;
    private static final int ERR_IO_FAULT = 3;
    private static final int ERR_PROC_INTERRUPT = 4;

    /**
     * De main methode kan volgende returncodes terug geven:
     *  <ul>
     *      <li>
     *          0 : Het programma werd succesvol afgerond.
     *      </li>
     *      <li>
     *          1 : Het programma werd opgeroepen met een verkeerd aantal argumenten.
     *      </li>
     *      <li>
     *          2 : Het programma werd opgeroepen met een bestandsnaam dat niet bestaat of ongeldig is.
     *      </li>
     *      <li>
     *          3 : Het programma onderging een fout bij I/O.
     *      </li>
     *      <li>
     *          4 : Het programma werd onderbroken terwijl een video aan het converteren was.
     *      </li>
     *  </ul>
     * @param args de argumenten die meegegeven worden 
     * 
     */
    public static void main(String[] args){
        Logger logger = Logger.getLogger("src.main.java.mp4converter");

        if (args.length != 1) { // Check for correct number of arguments
            System.out.println("Expected one argument (the input file), were " + args.length);
            System.exit(ERR_ARG_COUNT);
        }
        logger.info("Calling FFMPEG Constructor");
       
        try {
            FFMPEG ffmpeg = new FFMPEG(args[0]);
            logger.info("Calling FFMPEG.executeCommand()");
            ffmpeg.executeCommand();
        } catch (FileNotFoundException fnfe) {
            logger.warning(fnfe.getMessage());
            System.exit(ERR_FILE_NOT_EXISTS);
        } catch (IOException ioe) {
            logger.warning(ioe.getMessage());
            System.exit(ERR_IO_FAULT);
        } catch ( InterruptedException ie){
            logger.warning(ie.getMessage());
            System.exit(ERR_PROC_INTERRUPT);
        }
        System.exit(0);
    }
}
