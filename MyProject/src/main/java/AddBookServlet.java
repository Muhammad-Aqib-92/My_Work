import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/add")
public class AddBookServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String role = session != null ? (String) session.getAttribute("role") : null;

        if (role == null) {
            response.sendRedirect("signin.html");
            return;
        }

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        out.println("<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        out.println("<h1>Add a Book</h1>");
        out.println("<form action='add' method='POST'>");
        out.println("Author: <input type='text' name='author' required/><br>");
        out.println("Title: <input type='text' name='title' required/><br>");
        out.println("Category: <select name='category' required>");
        out.println("<option value='old'>Old</option>");
        out.println("<option value='new'>New</option>");
        out.println("</select><br>");
        out.println("<input type='submit' value='Add Book'/>");
        out.println("</form>");

        if ("user".equals(role)) {
            out.println("<p>You can only add books categorized as 'Old'.</p>");
        }
        
        if ("user".equals(role)) {
            out.println("<br><a href='userpanel.html'><button>Back to User Panel</button></a>");
            out.println("</body></html>");
        }
        if ("admin".equals(role)) {
            out.println("<br><a href='adminpanel.html'><button>Back to admin Panel</button></a>");
            out.println("</body></html>");
        }

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession(false);
        String role = session != null ? (String) session.getAttribute("role") : null;

        if (role == null) {
            response.sendRedirect("signin.html");
            return;
        }

        String author = request.getParameter("author");
        String title = request.getParameter("title");
        String category = request.getParameter("category");
        
        String userName;
        if (session.getAttribute("userName") != null) {
            userName = (String) session.getAttribute("userName");
        } else {
            userName = null;
        }


     
        if (author.isEmpty() || title.isEmpty() || category.isEmpty() || userName == null) {
            response.getWriter().println("<h1>Error: All fields are required.</h1>");
            return;
        }

        boolean isUser = "user".equals(role);
        boolean isAdmin = "admin".equals(role);

        if (isUser && !"old".equals(category)) {
        	response.getWriter().println("<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            response.getWriter().println("<h1>Error: You can only add books categorized as 'Old'.</h1>");
            response.getWriter().println("</body></html>");
            return;
        }

        if(isUser == true && "old".equals(category) || isAdmin == true && "new".equals(category)|| isAdmin == true && "old".equals(category)) {
        BookDao bookDao = new BookDao();
        boolean isAdded = bookDao.addBook(author, title, category, userName);

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        if (isAdded) {
        	
        	out.println("<html> <head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        	out.println("<h1>Book added successfully!</h1>");

        	String panelLink;
        	String panelName;

        	if (isAdmin) {
        	    panelLink = "adminpanel.html";
        	    panelName = "Admin";
        	} else {
        	    panelLink = "userpanel.html";
        	    panelName = "User";
        	}

        	out.println("<a href='" + panelLink + "'><button>Back to " + panelName + " Panel</button></a>");
        	out.println("</body></html>");
     
        } else {
            out.println("<html>");
            out.println("<head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
            out.println("<h1>Error: Failed to add the book.</h1>");
            out.println("<a href='" + (isAdmin ? "adminpanel.html" : "userpanel.html") + "'><button>Back to " + (isAdmin ? "Admin" : "User") + " Panel</button></a>");
            out.println("</body></html>");
        }

 
        bookDao.close();
    }
    }
}
