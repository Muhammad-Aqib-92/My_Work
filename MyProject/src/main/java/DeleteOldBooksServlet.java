import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/DeleteOldBooksServlet")
public class DeleteOldBooksServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);

        if (session == null || !"user".equals(session.getAttribute("role"))) {
            response.sendRedirect("signin.html");
            return;
        }

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        out.println("<h1>Delete a Book</h1>");
        out.println("<form action='DeleteOldBooksServlet' method='POST'>");
        out.println("Author: <input type='text' name='author' required/><br><br>");
        out.println("Title: <input type='text' name='title' required/><br><br>");
        out.println("<input type='hidden' name='category' value='old'/>");
        out.println("<br><input type='submit' value='Delete Book'/>");
       out.println("</form>");
        out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a></body></html>");

    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);

        if (session == null || !"user".equals(session.getAttribute("role"))) {
            response.sendRedirect("login.html");
            return;
        }

        String userName = (String) session.getAttribute("userName");
        String author = request.getParameter("author");
        String title = request.getParameter("title");
        String category = request.getParameter("category");

        if (author == null || title == null || category == null || author.isEmpty() || title.isEmpty() || userName == null) {
            response.getWriter().println("<h1>Error: Author, Title, Category, and User are required.</h1>");
            return;
        }

        if ("new".equals(category)) {
            response.getWriter().println("<h1>You do not have rights to delete new books.</h1>");
            return;
        }

       
        BookDao bookDao = new BookDao();
        boolean isDeleted = bookDao.deleteBook(author, title, category, userName);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        if (isDeleted) {
        	 out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Book deleted successfully!</h1>");
            out.println("<a href='userpanel.html'><button>Back to User Panel</button></a>");
            out.println("</body></html>");
        } else {
        	out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>You can only delete old books which you have uploaded.</h1>");
            out.println("<a href='userpanel.html'><button>Back to User Panel</button></a>");
            out.println("</body></html>");
        }

        // Close the BookDao connection
        bookDao.close();
    }
}
