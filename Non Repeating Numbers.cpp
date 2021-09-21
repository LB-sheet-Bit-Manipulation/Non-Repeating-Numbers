 vector<int> singleNumber(vector<int> a) 
    {
        // Code here.
        
        int XOR=a[0],n1=0,n2=0;
        vector<int> ans;
        
        //sabka XOR nikalo
        for(int i=1;i<a.size();i++)
        {
            XOR=XOR^a[i];
        }
        
        //ab ye jo hai isme un dono answers XOR hoga but apne ko vo numbers chaiye
        //alag karne ka ek tareeka hai. REFER u tube prepcoding video for this logic
        
        //ek mask bnao rightmost set bit of XOR ke liye
        
        /*
        
        RIGHMOST SET BIT NIKAALNE KI TRICK => set_bit_no = Xor & ~(Xor - 1);
        
        */
        int mask=(XOR & ~(XOR-1));
        
        //ab aise number jinkaa ye righmost bit set aata hai unka xor alag se nikaalo
        //bcoz answer mese koi to ek hi vaha present ho sakta ahai and rest cancels out
        //and jinka set nhi hai unka alag se nikalo
        //is tarah se dono number mil jaayenge
        
        for(int i=0;i<a.size();i++)
        {
            if(mask & a[i])
            {
                n1=n1^a[i];
            }
            else
            {
                n2=n2^a[i];
            }
        }
        
        if(n1<n2)
        {
        ans.push_back(n1);
        ans.push_back(n2);
        }
        else
        {
        ans.push_back(n2);
        ans.push_back(n1);
        }
        
        return ans;
    }
