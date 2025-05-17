import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/SignupServlet")
public class SignupServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
       
        String username = request.getParameter("username");
        String email = request.getParameter("email");
        String password = request.getParameter("pw");
        String role = request.getParameter("role");  

        
        if (username == null || email == null || password == null || username.isEmpty() || email.isEmpty() || password.isEmpty()) {
            response.setContentType("text/html");
            PrintWriter out = response.getWriter();
            out.println("<html><head><link rel='stylesheet' type='text/css' href='style.css'></head><body>");
            out.println("<h1>Error: All fields are required.</h1>");
            out.println("</body></html>");
            return;
        }

    
        BookDao bookDao = new BookDao();
        boolean isUserAdded = bookDao.addUser(email, username, password, role);

        bookDao.close();

   
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><link rel='stylesheet' type='text/css' href='style.css'></head><body>");

        if (isUserAdded) {
            HttpSession session = request.getSession();
            session.setAttribute("username", username);
            session.setAttribute("role", role);
            
          
            out.println("<h1>Signup successful! Welcome, " + username + "!</h1>");
            out.println("<a href='signin.html'><button>Go to Login</button></a>");
        } else {
      
            out.println("<h1>Signup failed. Email may already exist.</h1>");
            out.println("<a href='signup.html'><button>Try Again</button></a>");
        }

        out.println("</body></html>");
    }
}
