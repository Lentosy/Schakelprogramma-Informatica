package mp4converter;

import java.io.File;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.List;
import java.util.StringJoiner;

/**
 * Deze klasse stelt het programma 'ffmpeg' voor. 
 * De klasse maakt automatisch het ffmpeg commando aan en zal deze uitvoeren
 * indien de methode executeCommand() wordt aangeroepen.
 */
public class FFMPEG {

    /**
     * Dit attribuut stelt het bestand op het toestel voor. 
     */
    private File inputFile;
    /**
     * Dit attribuut specificeert de extensie naarwaar geconverteerd moet worden.
     * Momenteel is dit enkel .mp4 maar kan verandert worden door dit ook aan 
     * de constructor mee te geven
     */
    private final String outputFileType = "mp4";

    /**
     * De default constructor.
     * Het argument is een absoluut of relatief pad naar een bepaald bestand. De constructor 
     * voert dan een call uit naar de private methode setInputFile(input) waar het argument gecontroleerd zal worden.
     * @param input De bestandsnaam als string
     * @throws FileNotFoundException wanneer het bestand niet bestaat
     */
    public FFMPEG(String input) throws FileNotFoundException {
        setInputFile(input);
    }

    /**
     * De setter van het attribuut 'inputFile'.
     * Deze setter controleert of het argument wel degelijk een geldig bestand is op het toestel.
     * @param input De bestandsnaam als string
     * @throws FileNotFoundException
     * @throws IllegalArgumentException
     */
    private void setInputFile(String input) throws FileNotFoundException, IllegalArgumentException {     
        inputFile = new File(input);
        if (!inputFile.exists()) {
            throw new FileNotFoundException("The file '" + input + "' could not be found.");
        }
        
        List<String> validExtensions = Arrays.asList(".divx", ".mp4", ".avi", ".wmv", ".mov", ".qt", ".avchd", ".flv", ".swf", ".mpg", ".m4p", ".m4v", ".svi");
        
        String[] parts = input.split("\\.");
        
        if(parts.length < 2){ // geen geldige bestandsnaam
            throw new IllegalArgumentException("The file '" + input + "' does not have a valid format.");
        }
       
        String extension = "." + parts[parts.length - 1]; // split [FILENAME].[EXTENSION] and grab EXTENSION
        int i = 0;
        while(i < validExtensions.size() && !extension.equals(validExtensions.get(i))){
            i++;
        }
        
        if(i == validExtensions.size()){
            throw new IllegalArgumentException("The file '" + input + "' is of a wrong type.");
        }

    }

    /**
     * Dit commando zal het ffmpeg commando dat gegenereert wordt door de private 
     * methode generateCommand()
     * @throws java.lang.InterruptedException Wanneer het proces dat het commando uitvoert onderbroken wordt.
     * @throws IOException Wanneer er een probleem is met het uitvoeren van het proces dat het commando uitvoert
     */
    public void executeCommand() throws InterruptedException, IOException {
        String command = generateCommand();

        Runtime runtime = Runtime.getRuntime();
        Process process = runtime.exec(command);
        
        /* voor één of andere redenen gebruikt ffmpeg stderr voor normale output.
		we doen dit trouwens om er voor te zorgen dat het process voltooid wordt. */
        BufferedReader stdErr = new BufferedReader(new InputStreamReader(process.getErrorStream()));
        String s;
        while ((s = stdErr.readLine()) != null) {  }
        
    }
    
    /**
     * Deze methode genereert het ffmpeg commando dat gebruikt kan worden in de
     * terminal/console, of door een ander proces.
     * @return Het commando in String formaat
     */
    private String generateCommand() {
        StringJoiner ffmpegCommand = new StringJoiner(" ");

        String absolutePath = inputFile.getAbsolutePath();
        
        String parts[] = absolutePath.split("\\.");
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < parts.length - 1; i++){
            sb.append(parts[i]).append(".");
        } 
        String outputFile = sb.toString() + outputFileType;
        ffmpegCommand.add("ffmpeg");
        ffmpegCommand.add("-i").add(absolutePath);
        ffmpegCommand.add("-y"); // overschrijven forceren	
        ffmpegCommand.add(outputFile);
        return ffmpegCommand.toString();
    }
}
