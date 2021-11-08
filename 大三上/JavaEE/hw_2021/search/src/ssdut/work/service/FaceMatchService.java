package ssdut.work.service;

public interface FaceMatchService {

    public String match(String imgPath1, String imgPath2);

    public boolean matchResult(String imgPath1, String imgPath2);
}
