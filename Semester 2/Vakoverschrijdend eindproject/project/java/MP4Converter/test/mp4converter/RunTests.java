package mp4converter;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;

public class RunTests {

    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(FFMPEGTest.class);
        
       
        result.getFailures().forEach((failure) -> {
            System.out.println(failure.toString());
        });
        
        System.out.println("Testsuite klaar in " + result.getRunTime()+ " milliseconden");
        System.out.println("Aantal uitgevoerde testen : " + result.getRunCount());
        System.out.println("Aantal genegeerde testen : " + result.getIgnoreCount());
        System.out.println("Aantal gefaalde testen : " + result.getFailureCount());
    }
    
}
