import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class BookDao {

    private Connection con;

   
    public BookDao() {
        try {
            Class.forName("com.mysql.jdbc.Driver"); 
            String url = "jdbc:mysql://127.0.0.1/book_management";
            con = DriverManager.getConnection(url, "root", "root"); 
        } catch (Exception e) {
            System.out.println("Connection Failed: " + e.getMessage());
        }
    }

   
    public Books searchBook(String title, String author) {
        Books bk = null;
        try {
            String query = "SELECT * FROM books WHERE title = ? AND author = ?";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, title);
            ps.setString(2, author);
            ResultSet rs = ps.executeQuery();

            if (rs.next()) {
                String bookAuthor = rs.getString("author");
                String bookTitle = rs.getString("title");
                String category = rs.getString("category");
                String user = rs.getString("user");

                
                bk = new Books(bookAuthor, bookTitle, category, user);
            } else {
                System.out.println("Record Not Found");
            }
        } catch (Exception e) {
            System.out.println("Error in searchBook: " + e.getMessage());
        }
        return bk;
    }


    
    public Users authenticateUser(String email, String password, String role) {
        Users user = null;
        try {
            String query = "SELECT email, username, password, role FROM users WHERE email = ? AND password = ? AND role = ?";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, email);
            ps.setString(2, password);
            ps.setString(3, role);
            ResultSet rs = ps.executeQuery();

            if (rs.next()) {
                String fetchedEmail = rs.getString("email");
                String fetchedUsername = rs.getString("username");
                String fetchedPassword = rs.getString("password");
                String fetchedRole = rs.getString("role");

                user = new Users(fetchedEmail, fetchedUsername, fetchedPassword, fetchedRole);
            }

            rs.close();
            ps.close();
        } catch (Exception e) {
            System.out.println("Error in authenticateUser: " + e.getMessage());
        }
        return user;
    }
    
    public ResultSet getAllBooks() {
        ResultSet rs = null;
        try {
            String query = "SELECT author, title, category ,user FROM books";
            PreparedStatement ps = con.prepareStatement(query);
            rs = ps.executeQuery();
        } catch (Exception e) {
            System.out.println("Error in getAllBooks: " + e.getMessage());
        }
        return rs;
    }
    
    public ResultSet allusers() {
        ResultSet rs = null;
        try {
            String query = "SELECT * FROM users";
            PreparedStatement ps = con.prepareStatement(query);
            rs = ps.executeQuery();
        } catch (Exception e) {
            System.out.println("Error in getAllBooks: " + e.getMessage());
        }
        return rs;
    }
    
    
    public boolean deleteBook(String author, String title, String category, String userName) {
        boolean isDeleted = false;
        try {
            String query = "DELETE FROM books WHERE author = ? AND title = ? AND category = ? AND user = ?";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, author);
            ps.setString(2, title);
            ps.setString(3, category);
            ps.setString(4, userName);

            int row = ps.executeUpdate();
            isDeleted = row > 0;
        } catch (Exception e) {
            System.out.println("Error in deleteBook: " + e.getMessage());
        }
        return isDeleted;
    }
    public boolean updateBook(String newAuthor, String newTitle, String newCategory, String newUser,
            String oldAuthor, String oldTitle, String oldCategory, String oldUser) {
             boolean isUpdated = false;

              try {

                String query = "UPDATE books SET author = ?, title = ?, category = ?, user = ? WHERE author = ? AND title = ? AND category = ? AND user = ?";
                PreparedStatement ps = con.prepareStatement(query);

                ps.setString(1, newAuthor);
                ps.setString(2, newTitle);
                ps.setString(3, newCategory);
                ps.setString(4, newUser);
                ps.setString(5, oldAuthor);
                ps.setString(6, oldTitle);
                ps.setString(7, oldCategory);
                ps.setString(8, oldUser);


                int row = ps.executeUpdate(); 
                isUpdated = row > 0;  
} catch (Exception e) {
System.out.println("Error in updateBook: " + e.getMessage());
}

return isUpdated;
}
    
    public boolean admindeleteBook(String author, String title, String category) {
        boolean isDeleted = false;
        try {
            String query = "DELETE FROM books WHERE author = ? AND title = ? AND category = ?";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, author);
            ps.setString(2, title);
            ps.setString(3, category);
           
            int row = ps.executeUpdate();
            isDeleted = row > 0;
        } catch (Exception e) {
            System.out.println("Error in deleteBook: " + e.getMessage());
        }
        return isDeleted;
    }

    public boolean addBook(String author, String title, String category, String userName) {
        boolean isAdded = false;
        String sql = "INSERT INTO books(author, title, category, user) VALUES(?, ?, ?, ?)";
        try (PreparedStatement ps = con.prepareStatement(sql)) {
            ps.setString(1, author);
            ps.setString(2, title);
            ps.setString(3, category);
            ps.setString(4, userName);
            int row = ps.executeUpdate();
            isAdded = row > 0;
        } catch (Exception e) {
            System.out.println("Error in addBook: " + e.getMessage());
        }
        return isAdded;
    }
    
    public boolean addUser(String email, String username, String password, String role) {
        boolean isAdded = false;
        try {
            String query = "INSERT INTO users (email, username, password, role) VALUES (?, ?, ?, ?)";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, email);
            ps.setString(2, username);
            ps.setString(3, password);
            ps.setString(4, role);
            int rows = ps.executeUpdate();
            isAdded = rows > 0;
        } catch (Exception e) {
            System.out.println("Error in addUser: " + e.getMessage());
        }
        return isAdded;
    }
    
      public boolean deleteUser(String email) {
        boolean isDeleted = false;
        try {
            String query = "DELETE FROM users WHERE email = ?";
            PreparedStatement ps = con.prepareStatement(query);
            ps.setString(1, email);
            int rows = ps.executeUpdate();
            isDeleted = rows > 0;
        } catch (Exception e) {
            System.out.println("Error in deleteUser: " + e.getMessage());
        }
        return isDeleted;
    }

  
    public void close() {
        try {
            if (con != null) con.close();
        } catch (Exception e) {
            System.out.println("Error closing connection: " + e.getMessage());
        }
    }
}
    
    
    
    
    
    
    
    

