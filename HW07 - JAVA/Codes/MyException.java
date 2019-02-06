
/**
 * @author Furkan Ozev
 * @since 17-01-2019
 * This is a MyException class for throw.
 */
@SuppressWarnings("serial")
public class MyException extends Exception {
	
	/**
	 * Constructor that take message.
	 * @param message error message (String)
	 */
	public MyException(String message)
    {
        super(message);
    }
    /* Getter that get error message.
     * @see java.lang.Throwable#getMessage()
     */
    public String getMessage()
    {
        return super.getMessage();
    }
}
