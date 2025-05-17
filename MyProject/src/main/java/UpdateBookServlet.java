import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;

@WebServlet("/updateBookServlet")
public class UpdateBookServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
       
        HttpSession session = request.getSession(false);
        if (session == null) {
            response.sendRedirect("signin.html");
            return;
        }

    
        String role = (String) session.getAttribute("role");

       
        if (role == null || !role.equals("admin")) {
            response.sendRedirect("signin.html"); 
            return;
        }

        String oldAuthor = request.getParameter("oldAuthor");
        String oldTitle = request.getParameter("oldTitle");
        String oldCategory = request.getParameter("oldCategory");
        String oldUser = request.getParameter("oldUser");

        String newAuthor = request.getParameter("newAuthor");
        String newTitle = request.getParameter("newTitle");
        String newCategory = request.getParameter("newCategory");
        String newUser = request.getParameter("newUser");
        
        BookDao bookDao = new BookDao();
        boolean isUpdated = bookDao.updateBook(newAuthor, newTitle, newCategory, newUser, 
                                               oldAuthor, oldTitle, oldCategory, oldUser);

    
        response.setContentType("text/html");
        response.getWriter().println("<html>");
        response.getWriter().println("<head><title>Update Book</title>");
        response.getWriter().println("<link rel='stylesheet' type='text/css' href='style.css'>");
        response.getWriter().println("</head><body>");
        
        if (isUpdated) {
            response.getWriter().println("<h1>Book updated successfully!</h1>");
        } else {
            response.getWriter().println("<h1>Error: Failed to update the book.</h1>");
        }

        
        response.getWriter().println("<a href='adminpanel.html'><button>Back to Admin Panel</button></a>");
        response.getWriter().println("</body>");
        response.getWriter().println("</html>");
    }
}
