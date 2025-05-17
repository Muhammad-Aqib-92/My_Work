import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/DeleteUserServlet")
public class DeleteUserServlet extends HttpServlet {
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
        out.println("<h1>Delete a User</h1>");
        out.println("<form action='DeleteUserServlet' method='POST'>");
        out.println("Email: <input type='email' name='email' required/><br>");
        out.println("<input type='submit' value='Delete User'/>");
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

        if (email == null || email.isEmpty()) {
            response.setContentType("text/html");
            response.getWriter().println("<h1>Error: Email is required.</h1>");
            return;
        }

        BookDao bookDao = new BookDao();
        boolean isDeleted = bookDao.deleteUser(email);
        bookDao.close();

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        if (isDeleted) {
        	 out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>User deleted successfully!</h1>");
            out.println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            out.println("</body></html>");
        } else {
        	 out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Failed to delete the user. Check if the email is correct.</h1>");
            out.println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            out.println("</body></html>");
        }
    }
}
