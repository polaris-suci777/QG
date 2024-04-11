package weekfour.dao.lmpl;


import weekfour.pojo.User;

public class UserDaolmpl {
    public static String select(String username) {
        String sql="select * from tb_user where username = #{username}";
        return username;
    }

    public static void add(User user) {
        String sql="insert into tb_user values(null,#{username},#{password})";
    }


}