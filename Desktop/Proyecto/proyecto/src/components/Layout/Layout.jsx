import Footer from "../common/Footer/Footer";
import MainNavBar from "../common/MainNavBar/MainNavBar";


const Layout = ({children}) => {

    return ( 
      <>
      <MainNavBar/>
        {children}
      <Footer/>
      </>
    );
  }
   
  export default Layout;