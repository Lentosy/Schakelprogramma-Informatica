package mp4converter;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import mp4converter.FFMPEG;
import mp4converter.FFMPEG;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;


/**
 * Testklass voor de klass FFMPEG
 */
public class FFMPEGTest {
    
    private static final String BASE = "testresources/";
    
    private FFMPEG ffmpegInstance;
    
    private final String INPUT = BASE + "test.flv";
    private static final String OUTPUT = BASE + "test.mp4";
    
    
    /**
    * Remove the output of the test-file so we can test again
    */
    @BeforeClass
    public static void initialize(){
        
        File filesToCleanUp[] = { 
            new File(OUTPUT), 
            new File(BASE + "test.subtest.mp3") 
        };
   
        for(File file : filesToCleanUp){
            if(file.exists()){
                file.delete();
            }
        }
    }
      
    @Test
    public void correctConversionToMP4() throws IOException, InterruptedException{
       ffmpegInstance = new FFMPEG(INPUT);
       ffmpegInstance.executeCommand();
       final File output = new File(OUTPUT);
       assertEquals(output.exists(), true);
       output.delete();
    }    
    
    @Test
    public void correctConversionToMP4WithPathWithMutlipleDots() throws FileNotFoundException, IOException, InterruptedException{
        ffmpegInstance = new FFMPEG(BASE + "test.subtest.flv");
        ffmpegInstance.executeCommand();
        final File output = new File(BASE + "test.subtest.mp4");
        assertEquals(output.exists(), true);
        output.delete();
    }
    
    @Test(expected = NullPointerException.class)
    public void constructorThrowsExceptionIfInputIsNull() throws FileNotFoundException{
        ffmpegInstance = new FFMPEG(null);
    }
    
    @Test(expected = IllegalArgumentException.class)
    public void constructorThrowsExceptionIfInputDoesNotHaveAnExtension() throws FileNotFoundException {
        ffmpegInstance = new FFMPEG("test");
    }
    
    @Test(expected = IllegalArgumentException.class)
    public void constructorThrowsExceptionIfInputFileHasWrongExtension() throws FileNotFoundException{
        ffmpegInstance= new FFMPEG(BASE + "test.mp3");
    }
    
    @Test(expected = FileNotFoundException.class)
    public void constructorThrowsExceptionIfInputFileDoesNotExist() throws FileNotFoundException{
        ffmpegInstance= new FFMPEG("invalidfile.fake");
    }
    
}
