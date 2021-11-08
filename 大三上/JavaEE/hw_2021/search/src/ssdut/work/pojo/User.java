package ssdut.work.pojo;

public class User {
    private boolean isAdmin;
    private String username;
    private String password;
    private boolean isTeacher;
    private String id;
    private String path;
    static String defaultPath = "default.jpg";
    private static final String  absolutePath = "D:/文件/大三文件/Java EE/上机/第三次作业/web/image/";
    private Person person;

    public User() {
    }

    public User( String username, String password) {
        this.username = username;
        this.password = password;
    }

    public User(boolean isAdmin, String username, String password) {
        this.isAdmin = isAdmin;
        this.username = username;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public boolean isIsAdmin() {
        return isAdmin;
    }

    public void setIsAdmin(boolean admin) {
        isAdmin = admin;
    }

    public boolean isIsTeacher() {
        return isTeacher;
    }

    public void setIsTeacher(boolean teacher) {
        isTeacher = teacher;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public static String getDefaultPath() {
        return defaultPath;
    }

    public static String getAbsolutePath() {
        return absolutePath;
    }

    public Person getPerson() {
        return person;
    }

    public void setPerson(Person person) {
        this.person = person;
    }

    @Override
    public String toString() {
        return "User{" +
                "isAdmin=" + isAdmin +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", isTeacher=" + isTeacher +
                ", id='" + id + '\'' +
                ", path='" + path + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof User) {
            User u = (User) obj;
            return this.username.equals(u.username);
        }
        return super.equals(obj);
    }
}
