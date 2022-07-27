 let isConnectted = false;
      let port;
      let writer;
	  
	  const encoder = new TextEncoder();
	  
	    async function addEventListener() {
        if (!isConnectted) {
          alert("you must connect to the usb ");
          return;
        }
		
		 async function connectUSB() {
      try {
        const requestOptions = {
          filters: [{ usbVendorId: 0x2341 }],
        };
		
		 // Request an Arduino from the user.
        port = await navigator.serial.requestPort(requestOptions);
        await port.open({ baudRate: 9600 });
        writer = port.writable.getWriter();
        isConnectted = true;
      } catch (e) {
        console.log("err", e);
      }
    }
	}