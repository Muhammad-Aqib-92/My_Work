import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet("/ShowAllUsersServlet")
public class ShowAllUsersServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

   
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
      
        response.setContentType("text/html");

       
        HttpSession session = request.getSession(false);

        
        if (session == null || !session.getAttribute("role").equals("admin")) {
           
            response.sendRedirect("signin.html");
            return;
        }

        
        response.getWriter().println("<html>");
        response.getWriter().println("<head><title>All Users</title>");
        response.getWriter().println("<link rel='stylesheet' type='text/css' href='style.css'>");
        response.getWriter().println("</head><body>");
        response.getWriter().println("<h1>List of All Users</h1>");

        
        BookDao bookDao = new BookDao();
        ResultSet rs = bookDao.allusers();

        try {
            if (rs != null) {
                response.getWriter().println("<table border='1'>");
                response.getWriter().println("<tr><th>Password</th><th>Username</th><th>Email</th><th>Role</th></tr>");
                
                while (rs.next()) {
                	String password = rs.getString("password");
                    String username = rs.getString("username");
                    String email = rs.getString("email");
                    String role = rs.getString("role");

                    response.getWriter().println("<tr>");
                    response.getWriter().println("<td>" + password + "</td>");
                    response.getWriter().println("<td>" + username + "</td>");
                    response.getWriter().println("<td>" + email + "</td>");
                    response.getWriter().println("<td>" + role + "</td>");
                    response.getWriter().println("</tr>");
                }

                response.getWriter().println("</table>");
            } else {
                response.getWriter().println("<p>No users found.</p>");
            }
        } catch (SQLException e) {
            e.printStackTrace();
            response.getWriter().println("<p>Error retrieving users: " + e.getMessage() + "</p>");
        }      
        
        
        response.getWriter().println("<br><a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
        response.getWriter().println("</body>");
        response.getWriter().println("</html>");
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
      
        doGet(request, response);
    }
}
