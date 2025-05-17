
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;


@WebServlet("/admin")
public class admin extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false); // Avoid creating a new session
        boolean isAdmin = false;

       
        if (session != null && "admin".equals(session.getAttribute("role"))) {
            isAdmin = true;
        }

        if (!isAdmin) {
           
            response.sendRedirect("signin.html");
            return;
        }

     
        String adminName = (String) session.getAttribute("userName");

       
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

      
        out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head> <body>");

        if (adminName != null) {
            out.println("<h1>Welcome, " + adminName + " (Admin)</h1>");
        } else {
            out.println("<h1>Welcome, Admin</h1>");
        }

     
        out.println("<table>");

      
        out.println("<form action='add'>");
        out.println("<tr><td><input type='submit' name='aob' value='Add Book'></td></tr>");
        out.println("</form>");

      
        out.println("<form action='DeleteBookServlet'");
        out.println("<tr><td><input type='submit' name='db' value='Delete Book'></td></tr>");
        out.println("</form>");

        out.println("<form action='AddUserServlet'>");
        out.println("<tr><td><input type='submit' name='au' value='Add User'></td></tr>");
        out.println("</form>");

        out.println("<form action='DeleteUserServlet'>");
        out.println("<tr><td><input type='submit' name='du' value='Delete User'></td></tr>");
        out.println("</form>");

        out.println("<form action='ViewBooksServlet'>");
        out.println("<tr><td><input type='submit' name='vb' value='View Book'></td></tr>");
        out.println("</form>");

        out.println("<form action='SearchBookServlet'>");
        out.println("<tr><td><input type='submit' name='sb' value='Search Book'></td></tr>");
        out.println("</form>");

        out.println("<form action='AdminLogOutServlet'>");
        out.println("<tr><td><input type='submit' name='lo' value='Logout'></td></tr>");
        out.println("</form>");

        out.println("</table>");
        out.println("</body></html>");
    }


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }


    public admin() {
        super();
    }

 
}
