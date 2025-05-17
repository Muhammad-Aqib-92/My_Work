import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;

@WebServlet("/AdminLogOutServlet")
public class AdminLogOutServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
      
        HttpSession session = request.getSession(false);
        if (session != null) {
            session.invalidate();
        }else {
        	response.sendRedirect("signin.html");
        }

      
        response.setContentType("text/html");
        response.getWriter().println("<html><head><link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>");
        response.getWriter().println("<h1>You have successfully logged out.</h1>");
        response.getWriter().println("<a href='signin.html'>Sign In</a>");
        response.getWriter().println("</body></html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
