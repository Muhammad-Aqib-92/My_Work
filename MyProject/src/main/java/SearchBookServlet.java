import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/SearchBookServlet")
public class SearchBookServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false); 

        
        if (session == null || session.getAttribute("userName") == null) {
          
            response.sendRedirect("signin.html");
            return;
        }

        
        String userName = (String) session.getAttribute("userName"); 

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

               
        out.println("<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        out.println("<h1>Search Book</h1>");
        out.println("<p>Welcome, " + userName + "!</p>"); 
        out.println("<form action='SearchBookServlet' method='POST'>");
        out.println("<table>");
        out.println("<tr><td><label for='title'>Title:</label></td>");
        out.println("<td><input type='text' id='title' name='title' required /></td></tr>");
        out.println("<tr><td><label for='author'>Author:</label></td>");
        out.println("<td><input type='text' id='author' name='author' required /></td></tr>");
        out.println("<tr><td colspan='2'><input type='submit' value='Search' /></td></tr>");
        out.println("</table>");
        out.println("</form>");
        String role = (String)session.getAttribute("role");
        if("user".equals(role))
        {
        	 out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a>"); 
             out.println("</body></html>");
        	
        }else 
        {
        	out.println("<br><a href='adminpanel.html'><button>Back to admin Panel</button></a>"); 
            out.println("</body></html>");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false); 

      
        if (session == null || session.getAttribute("userName") == null) {
            response.sendRedirect("signin.html");
            return;
        }

        String userName = (String) session.getAttribute("userName"); 
        String title = request.getParameter("title").trim();
        String author = request.getParameter("author").trim();

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        if (title.isEmpty() || author.isEmpty()) {
        	 out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Error: Both Title and Author fields are required.</h1>");
            out.println("<br><a href='SearchBookServlet'><button>Try Again</button></a>");
            out.println("</body></html>");
            return;
        }

        BookDao bookDao = new BookDao();
        try {
            Books book = bookDao.searchBook(title, author);

            out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Search Results</h1>");
            out.println("<p>Welcome, " + userName + "!</p>"); 

            if (book != null) {
                out.println("<p>Book Found:</p>");
                out.println("<p>" + book.toString() + "</p>");
            } else {
                out.println("<p>No book found with the given title and author.</p>");
            }
            String role = (String)session.getAttribute("role");
            if("user".equals(role))
            {
            	 out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a>"); 
                 out.println("</body></html>");
            	
            }else 
            {
            	out.println("<br><a href='adminpanel.html'><button>Back to admin Panel</button></a>"); 
                out.println("</body></html>");
            }

           
        } catch (Exception e) {
        	 out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Error occurred while searching for the book.</h1>");
            out.println("<p>" + e.getMessage() + "</p>");
            out.println("<br><a href='SearchBookServlet'><button>Try Again</button></a>");
            out.println("</body></html>");
        } finally {
            bookDao.close(); // Explicitly closing the connection
        }
    }
}
