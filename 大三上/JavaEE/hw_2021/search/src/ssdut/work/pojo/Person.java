package ssdut.work.pojo;

public abstract class Person {

    String name;
    String phoneNumber;
    String qqNumber;
    String mail;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getQqNumber() {
        return qqNumber;
    }

    public void setQqNumber(String qqNumber) {
        this.qqNumber = qqNumber;
    }

    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public boolean checkName(String nName){
        return name.contains(nName);
    }

    public boolean checkPhoneNum(String nPhoneNum){
        return phoneNumber.contains(nPhoneNum);
    }

    public boolean checkQQNum(String nQQNum){
        return qqNumber.contains(nQQNum);
    }

    public boolean checkMail(String nMail){
        return mail.contains(nMail);
    }


}
