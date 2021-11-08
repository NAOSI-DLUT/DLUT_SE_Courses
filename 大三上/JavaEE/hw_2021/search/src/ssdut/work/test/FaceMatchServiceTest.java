package ssdut.work.test;

import org.junit.Test;
import ssdut.work.service.FaceMatchService;
import ssdut.work.service.impl.FaceMatchServiceImpl;

import static org.junit.Assert.*;

public class FaceMatchServiceTest {

    FaceMatchService faceMatchService = new FaceMatchServiceImpl();

    @Test
    public void matchResult() {
        String path = "C:\\Users\\hp\\Desktop\\新建文件夹\\";
        System.out.println(faceMatchService.matchResult(path+"temp1.jpg",path+"temp1_.jpg"));
    }
}