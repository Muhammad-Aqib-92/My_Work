import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/AddUserServlet")
public class AddUserServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        boolean isAdmin = false;

        if (session != null && "admin".equals(session.getAttribute("role"))) {
            isAdmin = true;
        }

        if (!isAdmin) {
            response.sendRedirect("signin.html");
            return;
        }

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        out.println("<h1>Add New User</h1>");
        out.println("<form action='AddUserServlet' method='POST'>");
        out.println("Email: <input type='email' name='email' required/><br>");
        out.println("Username: <input type='text' name='username' required/><br>");
        out.println("Password: <input type='password' name='password' required/><br>");
        out.println("Role: <select name='role' required>");
        out.println("<option value='' disabled selected>Select Role</option>");
        out.println("<option value='user'>User</option>");
        out.println("<option value='admin'>Admin</option>");
        out.println("</select><br>");
        out.println("<input type='submit' value='Add User'/>");
        out.println("</form>");
        out.println("<br><a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        boolean isAdmin = false;

        if (session != null && "admin".equals(session.getAttribute("role"))) {
            isAdmin = true;
        }
        
        if (!isAdmin) {
            response.sendRedirect("signin.html");
            return;
        }

        String email = request.getParameter("email");
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String role = request.getParameter("role");
        
      

        if (email == null || username == null || password == null || role == null ||
                email.isEmpty() || username.isEmpty() || password.isEmpty() || role.isEmpty()) {
            response.setContentType("text/html");
            response.getWriter().println("<h1>Error: All fields are required.</h1>");
            return;
        }

        BookDao bookDao = new BookDao();
        boolean isAdded = bookDao.addUser(email, username, password, role);
        bookDao.close();

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        if (isAdded) {
        	out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>User added successfully!</h1>");
            out.println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            out.println("</body></html>");
        } else {
        	out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Failed to add user. Email may already exist.</h1>");
            out.println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            out.println("</body></html>");
        }
    }
}
