package ssdut.work.pojo;

public class Student extends Person {

    String  id;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public boolean checkId(String nId){
        return id.contains(nId);
    }

    @Override
    public String toString() {
        return "Student{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", qqNumber='" + qqNumber + '\'' +
                ", mail='" + mail + '\'' +
                '}';
    }

    public String strInLine(){
        return String.format("<tr><th>学生</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th><th>%s</th></tr>",
                id,name,phoneNumber,qqNumber,mail);
    }
}
