import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;

@WebServlet("/ViewBooksServlet")
public class ViewBooksServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);

     
        if (session == null || session.getAttribute("role") == null) {
            response.sendRedirect("signin.html");
            return;
        }

        String role =(String)session.getAttribute("role");
               
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        out.println("<h1>Available Books</h1>");

        BookDao bookDao = new BookDao();
        try {
            ResultSet rs = bookDao.getAllBooks();

            if (rs != null) {
                out.println("<table border='1'>");
                out.println("<tr><th>Author</th><th>Title</th><th>Category</th><th>user</th></tr>");

                while (rs.next()) {
                    String author = rs.getString("author");
                    String title = rs.getString("title");
                    String category = rs.getString("category");
                    String user = rs.getString("user");
                    out.println("<tr><td>" + author + "</td><td>" + title + "</td><td>" + category + "</td><td>" + user + "</td><td></tr>");
                }

                out.println("</table>");
            } else {
                out.println("<p>No books available.</p>");
            }

            if ("admin".equals(role)) {
                out.println("<br><a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            } else if ("user".equals(role)) {
                out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a>");
            }

        } catch (Exception e) {
            out.println("<h2>Error: " + e.getMessage() + "</h2>");
        } finally {
            bookDao.close();
        }

        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
