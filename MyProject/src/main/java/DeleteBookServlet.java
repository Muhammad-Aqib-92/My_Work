import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/DeleteBookServlet")
public class DeleteBookServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    private BookDao bookDao = new BookDao();

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);

        if (session == null) {
            response.sendRedirect("signin.html");
            return;
        }

        String role = (String) session.getAttribute("role");

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");

        if ("user".equals(role)) {
         
            out.println("<h1>Delete an Old Book</h1>");
            out.println("<form action='DeleteBookServlet' method='POST'>");
            out.println("Author: <input type='text' name='author' required/><br><br>");
            out.println("Title: <input type='text' name='title' required/><br><br>");
            out.println("<input type='hidden' name='category' value='old'/>");
            out.println("<br><input type='submit' value='Delete Book'/>");
            out.println("</form>");
            out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a>");
        } else if ("admin".equals(role)) {
         
            out.println("<h1>Delete Book</h1>");
            out.println("<form action='DeleteBookServlet' method='POST'>");
            out.println("Author: <input type='text' name='author' required/><br><br>");
            out.println("Title: <input type='text' name='title' required/><br><br>");
            out.println("Category: <input type='text' name='category' required/><br><br>");
            out.println("<button type='submit'>Delete Book</button>");
            out.println("</form>");
            out.println("<br><a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
        } else {
            response.sendRedirect("signin.html");
        }

        out.println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);

        if (session == null) {
            response.sendRedirect("signin.html");
            return;
        }

        String role = (String) session.getAttribute("role");
        String userName = (String) session.getAttribute("userName");
        String author = request.getParameter("author");
        String title = request.getParameter("title");
        String category = request.getParameter("category");

        if (author == null || title == null || category == null || author.isEmpty() || title.isEmpty()) {
            response.getWriter().println("<h1>Error: All fields are required.</h1>");
            return;
        }

        boolean isDeleted = false;
        try {
            if ("user".equals(role)) {
               
                if (!"old".equals(category)) {
                    response.getWriter().println("<h1>You can only delete old books.</h1>");
                    return;
                }
                isDeleted = bookDao.deleteBook(author, title, category, userName);
            } else if ("admin".equals(role)) {
                
                isDeleted = bookDao.admindeleteBook(author, title, category);
            } else {
                response.sendRedirect("signin.html");
                return;
            }

            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            if (isDeleted) {
                out.println("<h1>Book deleted successfully!</h1>");
            } else {
                out.println("<h1>Failed to delete the book. Check the details and try again.</h1>");
            }

            if ("user".equals(role)) {
                out.println("<a href='userpanel.html'><button>Back to User Panel</button></a>");
            } else if ("admin".equals(role)) {
                out.println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
            }

            out.println("</body></html>");
        } catch (Exception e) {
            response.setContentType("text/html");
            response.getWriter().println("<h1>Error: " + e.getMessage() + "</h1>");
            e.printStackTrace();
        }
    }
}
